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
c:=b*2.5;
write(c);
if(c>5) then
f(b,a)
else
write(a);
c:=3+b*1.2-1.5;
write(c);

end.