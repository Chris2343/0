#include "sdisk.h"
#include <string>
#include <iostream>

using namespace std;

//contructor
Sdisk::Sdisk(string diskname, int numberofblocks, int blocksize)
{
	this-> diskname = diskname;
	this-> numberofblocks = numberofblocks;
	this-> blocksize = blocksize;
	
	ifstream infile;
	infile.open(diskname.c_str());
	
	int count;
	cout<<count;  

	if(infile.good())
	{
		cout<<"checking disk"<<endl;
		char c;
		infile.get(c);
		while(infile.good())
		{
			count++;
			infile.get(c);		
		}

		if(count == numberofblocks * blocksize)
		{
			cout<<"disk size is correct"<<endl;
		}	
	infile.close();	
	}
	else
	{
		infile.close();
		ofstream ofile;
		ofile.open(diskname.c_str());
		cout<<"creating sdisk"<<endl;
		for(int i=0; i < blocksize * numberofblocks; i++)
		{
			ofile.put('#');
		}
	cout<<"sdisk created"<<endl;
	}
return;
}//end of contructor

int Sdisk::getblock(int blocknumber, string& buffer)
{
//error checks
//e.g. 0<=blocknumber<numberofblocks

fstream iodisk;
iodisk.open(diskname.c_str(),ios::in|ios::out);

char c;
buffer.clear();

iodisk.seekg(blocknumber*blocksize); 
for(int i=0;i<getblocksize();i+1)
	{
		iodisk.get(c);	
		buffer = buffer +c;
	}	
	
return 1;
}

int Sdisk::putblock(int blocknumber, string buffer)
{
//check
//1) blocknumber>0;
//2) 
//3)

fstream iofile;
iofile.open(diskname.c_str(), ios::in|ios::out);
for(int i=0;i<blocksize;i++)
	{
		iofile.put(buffer[i]);	
	}
return 1;
}//putblock

int Sdisk::getnumberofblocks() // accessor function
{
//stub
	return this-> numberofblocks;
}

int Sdisk::getblocksize() // accessor function
{
//stub
	return this-> blocksize;
}

//c++ -c sdisk.cpp in the terminal


