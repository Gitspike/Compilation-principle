program main(input);
function f1(n1:integer):integer;
begin
    write(n1);
    f1:=3;
end;
function f2(n2:integer):integer;
var 
n3:integer;
begin
    f2:=f1(4)*2;
    
    n3:=f2;
    write(n3);
    
end;
begin
    
    f2(3);
end.
