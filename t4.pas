program main(input);
var 
book:record
id:integer
end;
a,b:integer;
c:array[1..3,2..4]of integer;
function f( n:integer):integer;
var v:integer;
begin
n:=5;

f:=n;
end;
begin
book.id:=2;
c[1][3]:=4;
a:=1;
f(a);
b:=f(c[1][3]);
writeln(b);
end.
read(a);
if(a>3) then
a:=1;
else
begin
    b:=1;
end;