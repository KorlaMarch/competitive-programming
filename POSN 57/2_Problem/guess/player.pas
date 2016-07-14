unit player;

interface

   function play(N: longint): longint;

implementation

   uses graderlib;
   function play(N: longint): longint;
      var i: longint;
   begin
      i := N-1;
      while i > 0 do begin
         if bigger(i) = 1 then begin
            play := i+1;
            i := -1;
         end;
         i := i -1;
      end;
      if i = 0 then play := 1;
   end;

begin
end.
