
%generate data
if (false)
    x=[ 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 ]

    fileID=fopen('datax1_double.bin','w');
    fwrite( fileID, x, 'double' );
    fclose(fileID);

    y=[ -1.69 -0.79 5.77 7.80 4.56 14.32 15.47 8.88 7.41 17.26 14.83 20.47 20.39 27.04 22.53 22.36 29.35 22.86 31.22 28.13 ]

    fileID=fopen('datay1_double.bin','w');
    fwrite( fileID, y, 'double' );
    fclose(fileID);
end


%load data
if (true)
    fileID=fopen('datax1_double.bin','r');
    x=fread( fileID, 'double' );
    fclose(fileID);

    fileID=fopen('datay1_double.bin','r');
    y=fread( fileID, 'double' );
    fclose(fileID);
end


start_ = datetime('now');
for i=1:1000000
    a = polyfit(x,y,1);  %a = robustfit (y,x);
end

end_ = datetime('now');
disp( a )
worktime=end_-start_;
disp ( worktime )





 
