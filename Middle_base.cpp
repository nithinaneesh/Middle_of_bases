/*
 * Middle_base.cpp
 * 
 * Copyright 2020 Nithin <snape@nithin-Predator-PH315-52>
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

int calculate_middle_of_base(std::string PDB_fname);

int main(int argc, char **argv)
{
    if(argc !=2) 
    {
        std::cout<<"Incorrect useage:\n Correct useage is: \n./"<<argv[0]<<" PDB_list.txt"<<std::endl;
    }
    std::ifstream PDB_list;
    std::string PDB_fname;
    PDB_list.open(argv[1]);
    if(PDB_list.is_open())
    {
        while(!std::getline(PDB_list, PDB_fname).eof())
        {
            calculate_middle_of_base(PDB_fname); 
        }
    }
    else std::cout <<"Unable to open "<<argv[1]<<std::endl;
	PDB_list.close();
	return 0;
}

int calculate_middle_of_base(std::string PDB_fname)
{
    std::ifstream PDB_file;
    std::string ATOM_Record;
    PDB_file.open(PDB_fname);
    std::ostringstream MB_STRING_STREAM;
    if(PDB_file.is_open())
    {
        std::cerr <<"The " <<PDB_fname<<" is being processed"<<std::endl;
        bool FIRST_ATOM_RECORD = true;
        bool NEW_RESIDUE_RECORD = true;
        int RESIDUE_NUMBER_PREV = 0;
        double xdist = 0.0, ydist = 0.0, zdist = 0.0;
        std::string MB_STRING = "";
        int atoms_processed = 0;
        while(!std::getline(PDB_file, ATOM_Record).eof())
        {
            
            
             if(ATOM_Record.substr(0,4) == "ATOM")
             {
                 
                 std::string RESIDUE_ID = ATOM_Record.substr(17,3);
                 std::string ATOM_ID = ATOM_Record.substr(11,5);
                 int RESIDUE_NUMER = stoi(ATOM_Record.substr(23,4));
                 double x_cord = stod(ATOM_Record.substr(30,8));
                 double y_cord = stod(ATOM_Record.substr(38,8));
                 double z_cord = stod(ATOM_Record.substr(46,8));
                 if (FIRST_ATOM_RECORD)
                 {
                     FIRST_ATOM_RECORD = false;
                     RESIDUE_NUMBER_PREV = RESIDUE_NUMER;
                 }
                 else
                 {
                     if (RESIDUE_NUMER != RESIDUE_NUMBER_PREV)
                     {
                         MB_STRING = "";
                         NEW_RESIDUE_RECORD = true;
                         RESIDUE_NUMBER_PREV = RESIDUE_NUMER;
                         
                         xdist = 0.0;
                         ydist = 0.0;
                         zdist = 0.0;
                        
                     }
                     
                 }
                 if(RESIDUE_ID == "  A" || RESIDUE_ID == "  G")
                 {
                     if(ATOM_ID == "  N9 " || ATOM_ID == "  C6 ")
                     {
                         std::cerr<<"The current ATOM_Record is:\t"<<ATOM_Record<<std::endl;
                         xdist+=x_cord;
                         ydist+=y_cord;
                         zdist+=z_cord;
                         ++atoms_processed;
                     }
                 }
                 if(RESIDUE_ID == "  U" || RESIDUE_ID == "  C")
                 {
                     if(ATOM_ID == "  N1 " || ATOM_ID == "  C4 ")
                     {
                         std::cerr<<"The current ATOM_Record is:\t"<<ATOM_Record<<std::endl;
                         xdist+=x_cord;
                         ydist+=y_cord;
                         zdist+=z_cord;
                         ++atoms_processed;
                     }
                 }
                 MB_STRING = ATOM_Record.replace(11,5,"  MB ");
                 if(atoms_processed == 2)
                 {
                      xdist= xdist/2;
                      ydist= ydist/2;
                      zdist= zdist/2;
                      std::stringstream ss;
                      ss<<std::setw(8)<<std::setprecision(3)<<std::setfill(' ')<<std::fixed<< xdist;
                      MB_STRING.replace(30,8,ss.str());
                      ss.str(std::string());
                      ss<<std::setw(8)<<std::setprecision(3)<<std::setfill(' ')<<std::fixed<< ydist;
                      MB_STRING.replace(38,8,ss.str());
                      ss.str(std::string());
                      ss<<std::setw(8)<<std::setprecision(3)<<std::setfill(' ')<<std::fixed<< zdist;
                      MB_STRING.replace(46,8,ss.str());
                      
                      MB_STRING_STREAM << MB_STRING;//<<std::endl;
                      atoms_processed =0;
                      
                 }
             }
             else continue;
        }
        
    std::cout<<MB_STRING_STREAM.str()<<std::endl;
        
    }
    else std::cout <<"Unable to open "<<PDB_fname<<std::endl;
    PDB_file.close();
    std::ofstream MB_file;
    
    return 0;
}
