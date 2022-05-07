program main(input);
var b,a,d:integer;
c:real;
e:array[1..3,1..4,1..5]of integer;
function f(  n1:integer; n4:integer):integer;
var v:integer;
begin
    write(n1);
    n1:=n1-1;
    f:=8;
end;
begin
e[1][1][1]:=2;
e[1][1][2]:=1;
b:=e[1][1][2]+4;
b:=b/0.1;
write(c);

c:=3+b*1.2-1.5;
write(c);
{f(a,b);}
end.