program main(input);
var 
a,b,d:integer;
g:boolean;
e,f:real;
c:array[1..3,2..4]of integer;
    function p(n2:integer):integer;
    var v:integer;
        procedure p1(var n1,n2:integer);
        var m:integer;
        begin
            m:=4;
            n1:=m;
            n2:=9;
        end;
    begin
        a:=1;
        v:=a;
        p:=2;
        p1(a,v);
    end;
begin
d:=7;
d:=6;
d:=9;
d:=p(b);
end.