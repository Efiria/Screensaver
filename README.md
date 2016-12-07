Projet ScreenSaver

Chef de Projet : Marc

il s'agit d'un systeme d'ecran de veille aléatoire qui fonctionne avec trois types
  - Statique
  - Dynamique
  - Interactif
  
But du projet : Faire des écrans de veille de Débian (3 différents). Lorsque l'on active grâce à une commande du terminal, un des trois doit apparaître au hasard.

Ecran n°1 : Ecran Statique -> Afficher le contenu d'un fichier contenant un dessin prédéfini.

1) Trouver le centre de la console à partir de sa taille afin de centrer le dessin (extension PBM) et l'afficher.
3) Débloquer l'écran lorsque n'importe quelle touche est pressé.

Ecran n°2 : Ecran Dynamique -> Afficher une horloge.

1) Trouver le centre de la console à partir de sa taille afin de centrer l'horloge (au format hh:mm:ss et extension PBM) et l'afficher.
2) Afficher << Cet écran sera actualisé dans quelques secondes >> en bas de la console (en dessous de l'horloge) avec un point s'ajoutant à la fin de phrase pendant N secondes.
3) Effacer tout les points lorsque ils atteignent le bord de la console et recommencer l'étape 2.
4) Actualiser l'heure à la fin du compteur N.
5) Débloquer l'écran de veille quand le processus est tué (ctrl+c).

Ecran n° 3 : Type interactif -> Afficher un avion mobile et intéractif.

1) Afficher un avion sur la console (extension PBM) avec une orientation aléatoire.
2) Faire avancer l'avion à vitesse constante sur une trajectoire rectiligne correspondant à son orientation.
3) Changer l'orientation de l'avion lorsque que l'on touche une des flèches du clavier ou alors ZQSD en le faisant pivoter sur son centre.
4) Ajuster sa trajectoire en fonction de son orientation.
5) Découper de tel façon à ce que lorsque il touche un bord de l'écran il apparait au côté opposé petit à petit (et disparait petit à petit à l'autre bord).
