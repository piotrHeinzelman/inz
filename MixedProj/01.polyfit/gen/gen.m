
%generate data
if (true)
    len=60
    x=[ 1:len ];

    fileID=fopen('datax20.bin','w');
    fwrite( fileID, x, 'double' );
    fclose(fileID);

    y=rand( 1, len );
    fileID=fopen('datay20.bin','w');
    fwrite( fileID, y, 'double' );
    fclose(fileID);
end

%disp( x );
%disp( y );





 
