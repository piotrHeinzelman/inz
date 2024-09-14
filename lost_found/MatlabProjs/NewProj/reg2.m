
x = (0:.11:100)
y = sin(x*.12)
          
start_ = datetime('now')
          
for i=1:99999
    robustfit (y,x)
end


end_ = datetime('now')
worktime=end_-start_



 
