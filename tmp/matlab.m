
%generate data
if (true)
    x=[ 1:4000000 ];

    fileID=fopen('datax4M_double.bin','w');
    fwrite( fileID, x, 'double' );
    fclose(fileID);

    y=rand( 1, 4000000 );
    fileID=fopen('datay4M_double.bin','w');
    fwrite( fileID, y, 'double' );
    fclose(fileID);
end

%disp( x );
%disp( y );





 
