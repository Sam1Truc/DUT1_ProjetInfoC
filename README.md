Projet :

  Le but est qu'à partir des fichiers : demande.don,cite.don,logement.don on puisse attribuer aux étudiants des logements (ou non, s'il n'y a plus de places dispo) et si on lui attribue un logement, alors on inscrira l'étudiant dans le fichier étudiant avec une référence de chambre que l'on sera aller chercher dans le fichier logement.don au préalable.

Carnet de fonctionnement du programme : 

Récupérer tous les fichiers existants (demande.don,cite.don,logement.don) et les charger dans des tableaux séparés. Trier le tableau Tdemande en fonction du handicap(Ils seront les premiers a avoir des logements comme ils ont des logements spéciaux) puis en fonction de l'échelon de bourse et enfin, si il y a égalité dans les deux précédentes conditions : on trie en fonction de l'ordre de création de la demande (on a ajouté un ordre à la structure Demande). Une fois le tableau trié, il y aura une fonction qui devra donc attribuer les logements en fonction de leur nombre dans l'ordre croissant du tableau Tdemande(voir ci-dessous).
Etat : 90%

A chaque fois qu'un étudiant peut se voir attribuer un logement, on devra inscrire l'étudiant dans le tableau Tétudiants puis enlever un logement du type demandé dans le tableau Tcité de la cité demandée et aussi récupérer dans le tableau Tlogements une référence d'un logement du type demandé en ayant vérifier que ce logement a bien un état à '0' (qui indique qu'il est dispo) et le transformé en '1' (pour indiquer qu'il est donc occupé). Ne pas oublier de sauvegarder les tableaux dans les fichiers qui leur sont attribués et libérer la mémoire des tableaux comme ils ne sont sauvegardés dans les fichiers. 
S'il reste des étudiants sans attribution on les gardes dans le tableau pour les réinscrire dans le fichier demande.don où ils seront donc considérés "en attente". 
Etat : 0%

Créer une fonction qui permette d'inscrire un nouvel étudiant dans le fichier demande.don en lui demandant de répondre via la console à chaque infos de la structure Demande pour pouvoir l'enregistrer (ATTENTION, pour l'ordre de demande, on devra charger le tableau Tdemande et faire une recherche du numéro d'ordre le plus élevé parmi toute la liste des demandes !). La fonction lancera ensuite la fonction d'attribution de logement qui permettra de savoir s'il a son logement ou s'il est en attente.
Etat : 0%

Créer la fonction Suppresion/Edition qui supprimera un étudiant du tableau Tétudiants et qui actualisera l'état du logement qu'il occupait ainsi que le nombre de logements de ce type disponibles dans le tableau Tcité et qui sauvegardera le tout dans les fichiers concernés.On relance à nouveau la fonction qui gère les demandes pour attribuer ce nouveau logement libre à un étudiant qui en aurait fait la demande mais qui serait sur liste d'attente pour ne pas laisser le logement vide.
Etat : 0%
