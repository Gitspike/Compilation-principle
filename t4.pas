program main(input);
var b,a,d:integer;
c:real;
e:array[1..3,1..3]of integer;
function f(  n1:integer; n4:integer):integer;
var v:integer;
begin
    write(n1);
    n1:=n1-1;
    if(n1>0) then
        f(n1,4)
end;
begin
a:=3;
f(a,b);
end.