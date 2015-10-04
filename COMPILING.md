# COMPILING

##Preprocessor defines
Use these defines as compiler defines (add them in the Makefile) to use them.
´GLOW_PRESET_2D´ sets the engine up for 2D mode
´GLOW_PRESET_3D´ sets the engine up for 3D mode

´GLOW_DEBUG´ enables engine debugging
´GLOW_N_ABORT_ON_FATAL´ NOT call abort() when logging a FATAL level (by default, Glow will abort() even if debugging is disabled)


###Recommended debug defines
´-DGLOW_PRESET_** -DGLOW_DEBUG´ (replace ** with either 3D or 2D)

###Recommended production defines
´-DGLOW_PRESET_**´
