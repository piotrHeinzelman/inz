
%generate data
if (false)
    x=[1:65535];

    fileID=fopen('datax_uint16.bin','w');
    fwrite( fileID, x, 'uint16' );
    fclose(fileID);

    y=randi([0,65535],1,65535);

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


start_ = datetime('now');
for i=1:10000
    a = polyfit(x,y,1);  %a = robustfit (y,x);
end

end_ = datetime('now');
disp( a )
worktime=end_-start_;
disp ( worktime )





 
