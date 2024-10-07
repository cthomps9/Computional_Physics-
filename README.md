# Computional_Physics-

Growth of an PROJECT: Clathrin Coated Pit Modeling:
 Pit

Summary: This code uses the formula written, described, and used in the paper called "Force Generation by Endocytic Actin Patches in Budding Yeast by Anders E Carlsson and Philip V. Bayly" to model the growth of an endocytic pit. 

Purpose: The purpose of this code is to simulate the growth of an Endocytic pit by incorporating some important variables. 

Operations to Run Code:

1st: We want to create the datasets beta.dat and RadiusandAlpha.dat. To create this dataset we want to type in "make -f make_parameters_of_growth" in the command list of the terminal in the folder. This will create the initial parameters that will be used in the growth of the pit.

2nd: We want to insert these equations into our model, which is done using the code called "growth_of_endocytic_site.cpp". We will make that file by typing, "make_growth_of_endocytic_site" in the command list of the terminal in the folder.  

3rd: Then use the plt file labeled, "Growth_using_database.plt" to plot the dataset. 

4th: To validate this code take a look at  figure 5. in the original paper. The numbers are not  exact because the paper uses software that takes in 8 more factors than I did. However the graphs are both extremely close and make sense factor wise. If you chose a large value for alpha then the pit would become larger within reason but not beyond the largest extreme for a clathrin coated pit. 

5th: Another validation is the use of the "Simple_Dimple_chars.cpp". In that code I write some simple code that tracks with what the growth of a "dimple" would be, which is the  simplest and basic form that a pit would model over time. If you run the plt labeled "Height_Profile.plt", then you will see that the simple dimple is the inverse of the growth of the pit. I.e. the simple strinks as x and y become bigger and the pit grows over time.

More ambitious steps: 
	1 - Increase the amount of input parameters and put them in a .dat 
	2 - Use a physics based render to generate a 3-D model of the pit using the information given by the .dat for one point in time for one simple set of inputs.
	3 - Render a 3-d model of the pit before and after for several different conditions. 
	4 - If the steps above work, 3-D models a timelapse model. 
