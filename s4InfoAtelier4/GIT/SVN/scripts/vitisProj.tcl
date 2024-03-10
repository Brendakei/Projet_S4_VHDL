# 
# Pour lancer : 
# Ouvrir "Xilinx Software Command Line Tool 2020.2" (XSCT)
# Lancer le script avec la commande suivante: 
#		source D:/ZYBO/Work-2020.2/Ateliers/Atelier3-Git/scripts/vitisProj.tcl

# nom du projet
set app_name s4InfoAtelier4

# spécifier le répertoire où placer le projet
set workspace C:/Travail/s4InfoAtelier4/GIT/SVN/work/Vitis_workspace

# Paths pour les fichiers sources c/c++/h
set sourcePath C:/Travail/s4InfoAtelier4/GIT/SVN/vitisProj/src

# Path pour le fichier .xsa
set hw C:/Travail/s4InfoAtelier4/GIT/SVN/work/s4InfoAtelier4/atelier4_wrapper.xsa

# Créer le workspace
file delete -force $workspace
setws $workspace
cd $workspace

# Créer le projet. La plateform va être créée automatiquement par XSCT
app create -name $app_name -hw $hw -os {standalone} -proc {ps7_cortexa9_0} -template {Empty Application} 

# Importation des fichiers sources
importsources -name $app_name -path $sourcePath -soft-link
importsources -name $app_name -path $sourcePath/lscript.ld -linker-script

# Compiler le projet
app build -name $app_name