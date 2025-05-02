; Provided under the CC0 license. See the included LICENSE.txt for details.

 processor 6502
 include "vcs.h"
 include "macro.h"
 include "DPCplus.h"
 include "DPCplusELFbB.h"
 include "2600basic_variable_redefs.h"
     ORG $0000
     RORG $0000
     dc "DPC+ELF"
     ORG $1080
     RORG $1080

