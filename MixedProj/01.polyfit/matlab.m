
cycles=1000;

%generate data
if (false)
    x=[ 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 ]

    fileID=fopen('datax_uint16.bin','w');
    fwrite( fileID, x, 'uint16' );
    fclose(fileID);

    y=[ -1.69 -0.79 5.77 7.80 4.56 14.32 15.47 8.88 7.41 17.26 14.83 20.47 20.39 27.04 22.53 22.36 29.35 22.86 31.22 28.13 ]

    fileID=fopen('datay_uint16.bin','w');
    fwrite( fileID, y, 'uint16' );
    fclose(fileID);
end


%load data
if (true)
    fileID=fopen('datax_uint16.bin','r');
    x=fread( fileID, 'uint16' );
    fclose(fileID);

    fileID=fopen('datay_uint16.bin','r');
    y=fread( fileID, 'uint16' );
    fclose(fileID);
end


ST = datetime('now');
for i = 1:cycles
    a = polyfit(x,y,1);
end

ED = datetime('now');

D = duration( ED-ST, 'FORMAT', 'mm:ss.SSSSSS' );
L = size( x );
fprintf(' duration: ' );
disp( D );
fprintf(' X[%i] * %i', L(1), cycles );
fprintf('\n result: ' );
disp( a );





 
