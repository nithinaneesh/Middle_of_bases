/*
 * MB_distances.cpp
 * 
 * Copyright 2020  <nchandran@ouzo>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */



#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>

int main(int argc, char **argv)
{
    if(argc != 3) std::cout<<"Incorrect useage:\n Correct useage is: \n"<<argv[0]<<" MB.pdb rmsd_file.txt"<<std::endl;
    std::ifstream PDB_fname;
    std::string ATOM_Record;
    std::stringstream pdb, rmsd_string;
    PDB_fname.open(argv[1]);
    if(PDB_fname.is_open())
    {
        pdb << PDB_fname.rdbuf();
        PDB_fname.close();
    }
    else std::cout <<"Unable to open "<<argv[1]<<std::endl;
    std::string line;
    std::vector<std::string> atoms;
    while(std::getline(pdb,line))   if(line.substr(0,4) == "ATOM")  atoms.push_back(line);
    for (size_t i=0; i<atoms.size();++i)
    {
        auto x1=stof(atoms.at(i).substr(30,8));
        auto y1=stof(atoms.at(i).substr(38,8));
        auto z1=stof(atoms.at(i).substr(46,8));
        for (size_t i=0; i<atoms.size();++i)
        {
            auto x2=stof(atoms.at(i).substr(30,8));
            auto y2=stof(atoms.at(i).substr(38,8));
            auto z2=stof(atoms.at(i).substr(46,8));
            auto dist = sqrt( (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) + (z1 - z2)*(z1 - z2));
            rmsd_string<<dist<<"  ";
        }
        rmsd_string<<std::endl;
    }
    std::ofstream rmsd_file;
    rmsd_file.open(argv[2]);
    rmsd_file<<rmsd_string.str();
    rmsd_file.close();
    return 0;
}

