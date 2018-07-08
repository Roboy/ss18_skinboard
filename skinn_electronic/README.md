<h1>skinn electronic</h1>
<h2>basic concept</h2>
The task to controll/measure the leds and sensors of the skin, has been splited into two subtasks. 
The LED controller, which are connected via daisy chain and the the Sensor controll unit. 
<p align="center">
  <img src="skinnElectronicOverview.jpg" width="350" title="hover text">
  <img src="your_relative_path_here_number_2_large_name" width="350" alt="Overview">
</p>
</br>
<h3>LED controller<h3>
The LED controller will cycle through every member of the daisy chain. To initialize this process there has to be high impulse one the first data1 connection which will lead to high output on the data2 line (synced with rising edge of the clk). 
<h3>Sensor CU<h3>
