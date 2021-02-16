{
// File pointer 
  
  /* ifstream fin;
    // Open an existing record 
    fin.open("HistParameters.csv");
    if(fin.fail())
       {cout<<"The file doesn't exist"<<endl;
       }

    int lines=0,Bins=0;
    float xMin=999,xMax=999;
    string variable;
    std::cout<<"fileexists"<<std::endl;
    //  while (!fin.eof())
    string line;
    for(lines=0;lines<5;lines++)
      {
	lines++;
	fin>>line;
	std::cout<<line<<" \n";
	//std::cout<<"Reading line "<<lines<<" ...."<<std::endl;
	
        //fscanf(fin,"%s,%i,%f,%f \n",&variable, &Bins,&xMin,&xMax);
	//	fin>>variable>>",">>Bins>>",">>xMin>>",">>xMax>>"\n";
	//getline ( fin, variable, ',' );
	//getline ( fin, Bins, ',' );
	//getline ( fin, xMin, ',' );
	//getline ( fin, xMax, ',' );
	std::cout<<lines<<", "<<variable<<", "<<Bins<<", "<<xMin<<", "<<xMax<<" \n"<<std::endl;
	}
    fin.close();
  */

  FILE *HistPars = fopen("HistParameters.csv","r");
   int lines=0,Bins=0; float xMin,xMax; char word[80];
    while(!feof(fp))
      {
	fscanf(fp,"%i, %f ,%f ,%s \n",&Bins,&xMin,&xMax,word);
	std::cout<<Bins<<", "<<xMin<<", "<<word<<" \n"<<std::endl;
	
      }

fclose(fp);
  }
