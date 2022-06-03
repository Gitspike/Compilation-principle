{非递归求最大公因数}
program main(input);
var x,y,result:integer;

function getgcd(a,b:integer):integer;
var temp:integer;
begin
    while b<>0 do
    begin
        temp := b;
        b := a mod b;
        a := temp;
    end;
getgcd:=a;
end;

begin
    read(x);
    read(y);
    result:=getgcd(x,y);
    write(result);
end.