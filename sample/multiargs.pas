program main(input);
var a:integer;
function f1(n1:integer):integer;
begin
    write(n1);
    f1:=3;
end;
function f2(n3,n2:integer):integer;
var 
n3:integer;
begin
    f2:=f1(4)*2;
    
    n3:=f2;
    
end;
begin
    a:=7;
    write(f2(2,3),a);
end.