unit graderlib;

interface
   function bigger(K: longint): longint;

implementation
   uses gradershare;

   function bigger(K: longint): longint;
   begin
      if secret > K then bigger := 1
      else bigger := 0;
   end;

begin

end.
