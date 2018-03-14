// C version
FILE *ifp = fopen( "example.bin", "rb" );
fseek( ifp, 0, SEEK_END );
size_t len = ftell( ifp );
fseek( ifp, 0, SEEK_SET );
fclose( ifp );
printf( "size is: %d bytes.\n", len );

// C++ version
streampos begin,end;
ifstream ifs( "example.bin", ios::binary );
begin = ifs.tellg();
ifs.seekg( 0, ios::end ); // ifs.seekg( 0 ); 回到开头
end   = ifs.tellg();
ifs.close();
cout << "size is: " << (end-begin) << " bytes.\n";
