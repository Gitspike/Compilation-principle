program main(input);
const
    LENGTH=100;
var
    n:integer;{个数}
    i:integer;
    data:array[0..100]of integer;
    a:integer;
procedure sort;
    var
        j,k:integer;
        lstart:integer;
        lend:integer;
        rstart:integer;
        rend:integer;
        temdata:array[0..100]of integer;
    begin
        j:=1;
        lstart:=0;
        lend:=0;
        rstart:=0;
        rend:=0;
        while j<n do
        begin
            lstart:=0;
            while lstart<n-j do
            begin
                lend:=lstart+j;
                rstart:=lstart+j;
                rend:=rstart+j;
                if rend>n then
                    rend:=n; 
                k:=0;
                while ((lstart<lend) and (rstart<rend)) do
                begin
                    if data[lstart]<data[rstart] then
                        begin
                        temdata[k]:=data[lstart];
                        k:=k+1;
                        lstart:=lstart+1;
                        end
                    else
                        begin
                        temdata[k]:=data[rstart];
                        k:=k+1;
                        rstart:=rstart+1;
                        end
                end;
                while lstart<lend do
                begin
                    temdata[k]:=data[lstart];
                    k:=k+1;
                    lstart:=lstart+1;
                end;
                while k>0 do
                begin
                    rstart:=rstart-1;
                    k:=k-1;
                    data[rstart]:=temdata[k];                 
                end;
            lstart:=rend;    
            end;
            j:=j*2;
        end;
    end;
begin
    read(n);
    i:=0;
    while i<n do
    begin
        read(a);
        data[i]:=a;
        i:=i+1;
    end;
    sort;
    i:=0;
    while i<n do
    begin
        write(data[i]);
        i:=i+1;
    end;
end.
