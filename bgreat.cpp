/*****************************************************************************
 *   Bgreat : De Bruijn Graph Read Mapping Tool
 *   Copyright (C) 2014  INRIA
 *   Authors: Antoine Limasset
 *   Contact: antoine.limasset@inria.fr, INRIA/IRISA/GenScale, Campus de Beaulieu, 35042 Rennes Cedex, France
 *   Source: https://github.com/Malfoy/BGREAT
 *
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Affero General Public License as
 *  published by the Free Software Foundation, either version 3 of the
 *  License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Affero General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*****************************************************************************/


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>
#include <ctime>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <chrono>
#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <unordered_map>
//#include <sparsehash/sparse_hash_map>
//#include <sparsehash/dense_hash_map>
#include <set>
#include <algorithm>
#include <chrono>
#include <map>
#include <set>
#include "aligner.h"



using namespace std;



int main(int argc, char ** argv){
	srand (time(NULL));

	if(argc<2){
		cout<<"Arguments : [read file]  [k](31) [unitig file](unitig.dot) [error allowed](2) [number of thread](1) [path file](path) [no overlap file](noOverlap.fa) [not aligned file](notAligned.fa)"<<endl;
		exit(0);
	}

	if(argc==2){
		string reads=argv[1];
		string unitigs="unitig.dot";
		int ka=31;
		auto start=chrono::system_clock::now();
		Aligner supervisor(reads,unitigs,"paths","noOverlap.fa","notAligned.fa",ka,1,2);
		supervisor.indexUnitigs();
		supervisor.alignAll(true);
		auto end=chrono::system_clock::now();auto waitedFor=end-start;cout<<"Last for "<<chrono::duration_cast<chrono::seconds>(waitedFor).count()<<" seconds"<<endl<<endl;
	}


	if(argc==3){
		string reads=argv[1];
		string karg=argv[2];
		string unitigs="unitig.dot";
		int ka=stoi(karg);
		auto start=chrono::system_clock::now();
		Aligner supervisor(reads,unitigs,"paths","noOverlap.fa","notAligned.fa",ka,1,2);
		supervisor.indexUnitigs();
		supervisor.alignAll(true);
		auto end=chrono::system_clock::now();auto waitedFor=end-start;cout<<"Last for "<<chrono::duration_cast<chrono::seconds>(waitedFor).count()<<" seconds"<<endl<<endl;
	}

	if(argc==4){
		string reads=argv[1];
		string karg=argv[2];
		string unitigs=argv[3];
		int ka=stoi(karg);
		auto start=chrono::system_clock::now();
		Aligner supervisor(reads,unitigs,"paths","noOverlap.fa","notAligned.fa",ka,1,2);
		supervisor.indexUnitigs();
		supervisor.alignAll(true);
		auto end=chrono::system_clock::now();auto waitedFor=end-start;cout<<"Last for "<<chrono::duration_cast<chrono::seconds>(waitedFor).count()<<" seconds"<<endl<<endl;
	}

	if(argc==5){
		string reads=argv[1];
		string karg=argv[2];
		string unitigs=argv[3];
		string errors=argv[4];
		int ka=stoi(karg);
		auto start=chrono::system_clock::now();
		Aligner supervisor(reads,unitigs,"paths","noOverlap.fa","notAligned.fa",ka,1,stoi(errors));
		supervisor.indexUnitigs();
		supervisor.alignAll(true);
		auto end=chrono::system_clock::now();auto waitedFor=end-start;cout<<"Last for "<<chrono::duration_cast<chrono::seconds>(waitedFor).count()<<" seconds"<<endl<<endl;
	}

	if(argc==6){
		string reads=argv[1];
		string karg=argv[2];
		string unitigs=argv[3];
		string errors=argv[4];
		string threads=argv[5];
		int ka=stoi(karg);
		auto start=chrono::system_clock::now();
		Aligner supervisor(reads,unitigs,"paths","noOverlap.fa","notAligned.fa",ka,stoi(threads),stoi(errors));
		supervisor.indexUnitigs();
		supervisor.alignAll(true);
		auto end=chrono::system_clock::now();auto waitedFor=end-start;cout<<"Last for "<<chrono::duration_cast<chrono::seconds>(waitedFor).count()<<" seconds"<<endl<<endl;
	}

	if(argc==7){
		string reads=argv[1];
		string karg=argv[2];
		string unitigs=argv[3];
		string errors=argv[4];
		string threads=argv[5];
		string pathFile=argv[6];
		int ka=stoi(karg);
		auto start=chrono::system_clock::now();
		Aligner supervisor(reads,unitigs,pathFile,"noOverlap.fa","notAligned.fa",ka,stoi(threads),stoi(errors));
		supervisor.indexUnitigs();
		supervisor.alignAll(true);
		auto end=chrono::system_clock::now();auto waitedFor=end-start;cout<<"Last for "<<chrono::duration_cast<chrono::seconds>(waitedFor).count()<<" seconds"<<endl<<endl;
	}

	if(argc==8){
		string reads=argv[1];
		string karg=argv[2];
		string unitigs=argv[3];
		string errors=argv[4];
		string threads=argv[5];
		string pathFile=argv[6];
		string noOverlapFile=argv[7];
		int ka=stoi(karg);
		auto start=chrono::system_clock::now();
		Aligner supervisor(reads,unitigs,pathFile,noOverlapFile,"notAligned.fa",ka,stoi(threads),stoi(errors));
		supervisor.indexUnitigs();
		supervisor.alignAll(true);
		auto end=chrono::system_clock::now();auto waitedFor=end-start;cout<<"Last for "<<chrono::duration_cast<chrono::seconds>(waitedFor).count()<<" seconds"<<endl<<endl;
	}

	if(argc==9){
		string reads=argv[1];
		string karg=argv[2];
		string unitigs=argv[3];
		string errors=argv[4];
		string threads=argv[5];
		string pathFile=argv[6];
		string noOverlapFile=argv[7];
		string notAlignedFile=argv[8];
		int ka=stoi(karg);
		auto start=chrono::system_clock::now();
		Aligner supervisor(reads,unitigs,pathFile,noOverlapFile,notAlignedFile,ka,stoi(threads),stoi(errors));
		supervisor.indexUnitigs();
		supervisor.alignAll(true);
		auto end=chrono::system_clock::now();auto waitedFor=end-start;cout<<"Last for "<<chrono::duration_cast<chrono::seconds>(waitedFor).count()<<" seconds"<<endl<<endl;
	}

	if(argc==10){
		string reads=argv[1];
		string karg=argv[2];
		string unitigs=argv[3];
		string errors=argv[4];
		string threads=argv[5];
		string pathFile=argv[6];
		string noOverlapFile=argv[7];
		string notAlignedFile=argv[8];
		string opt=argv[9];
		if(opt=="-b"){
		int ka=stoi(karg);
		auto start=chrono::system_clock::now();
		Aligner supervisor(reads,unitigs,pathFile,noOverlapFile,notAlignedFile,ka,stoi(threads),stoi(errors));
		supervisor.indexUnitigs();
		supervisor.alignAll(false);
		auto end=chrono::system_clock::now();auto waitedFor=end-start;cout<<"Last for "<<chrono::duration_cast<chrono::seconds>(waitedFor).count()<<" seconds"<<endl<<endl;
		}else{
			cout<<"not recognized option did you mean -b for bruteforce ?"<<endl;
		}

	}
}
