path="./"
#input_file_name="calibration.*"
output_file_name="calibration.gcode"


g_init="$(cat << EOF
M103
M73 P0
G21
G90
EOF
)"

g_homing=$(cat << EOM
G162 X Y F2500
G161 Z F1100
M132 X Y Z A B
EOM
)

g_end=$(cat << EOM
M73 P100
G0 Z150
M18
M109 S0 T0
M104 S0 T0
M104 S0 T1
G162 X Y F2500
M18
M70 P5 (Roboy)
EOM
)

echo "$g_init" > "$output_file_name"
echo "$g_homing" >> "$output_file_name"
echo "$g_end" >> "$output_file_name"
