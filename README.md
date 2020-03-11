# Middle_of_bases
The middle of base is the midpoint between
- N1 and C4 atoms in purines
- N9 and C6 atoms in pyramidines
 
## Middle_base.cpp
 The program calculates the middle points of the bases provided in the input PDB files. The input files are expected to be in standard PDB format. 
 
 ```
 ./Middle_base pdb_file_list
 ```

##MB_distances
The program calculates the distances between different atoms in the input PDB file and output as a matrix file with distances seperated by two spaces (two spaces was a requirement for a program I used this as input).
 ```
 ./Middle_distances pdb_file output_distance_matrix_file
 ```