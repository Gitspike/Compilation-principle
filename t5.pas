program main(input);
procedure e(a,b:integer);
var c:integer;
begin
    c:=a;
    a:=b;
    b:=c;
end;
begin

e(1,2);
end.