{

    FILE* pFile;
  pFile = fopen("WritingCSV.CSV","w");

  TString s1="CosmicTF", s2="CTF", s3="DeltaR";
  
  fprintf(pFile,", , %s,%s,%s \n",s1.Data(),"CTF",s3.Data());

  fclose(pFile);

}
