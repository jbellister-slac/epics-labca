// Addinter for file ezca
// for hppa/sun-solaris/linux/dec
//--------------------------------
//Scilab functions 
ezca_funs=[...
  'ezcaGet';
  'ezcaPut';
  'ezcaGetNelem';
  'ezcaGetControlLimits';
  'ezcaGetGraphicLimits';
  'ezcaGetStatus';
  'ezcaDebugOn';
  'ezcaLibInit';
  'ecdrGet']
ifile='ezca.o' 
ufiles=['ecget.o ezcaWrap.o -L/home/till/epics/extensions/lib/linux-ppc -L/home/till/epics/base/lib/linux-ppc -lezca -lca -lCom']
//ufiles=[]
files = [ifile,ufiles] 
addinter(files,'ezca',ezca_funs);
ezcaLibInit();
