# SOLID C++ RPG Implementation
SOLID regroupe 5 principes de conception permettant de produire des architectures plus compréhensibles, flexibles et de faciliter leurs maintenances.
## Responsabilité Unique (Single Responsibility Principle)
#### Description
Une classe doit avoir uniquement une seule responsabilité. Si l’on doit modifier cette classe, cela doit être dans l’unique but de modifier le comportement de cette classe.
En respectant cette règle, cela rend le code source plus facile à comprendre et à maintenir.

#### Exemple: Classes World & SaveManager
On pourrait ajouter une fonction de sauvegarde à la classe World mais cela violerai le principe de responsabilité unique.
La classe World doit uniquement être responsable du fonctionnement de la simulation si l'on souhaite ajouter une fonction pour sauvegarder créer un classe qui sera responsable de sauvegarder l'état du monde.
> voir les classes [World](SOLID_Exemple/include/solid_exemple_lib/world.h) & [SaveManager](SOLID_Exemple/include/solid_exemple_lib/save_manager.h)
## Ouvert / Fermé (Open/Close Principle)
#### Description
Ce principe défini qu’un programme doit être ouvert à l'extension mais fermé à la modification. En d’autre terme si l’application est amenée à étendre ses fonctionnalités, cela doit se faire par une extension du code source et non par sa modification.

Une fois qu’une classe est approuvée via des revues de code et des tests unitaires, elle ne doit plus être modifiée.
Ce principe permet de rendre le code source plus flexible et de diminuer les dépendances.

#### Exemple: Classe Requirement
Cette classe est abstraite, elle à été implémenté pour permettre l'ajout de futur exigence. Les classe étendue de la classe abstraite doivent définir le comportement de leurs méthodes afin de crée de nouvelle exigence.
> voir la classe [Requirement](SOLID_Exemple/include/solid_exemple_lib/requirement.h)
## Substitution de Liskov (Liskov Substitution Principle)
#### Description
Le principe de substitution de Liskov évoque la notion de sous-type. Pour tout sous type d’une classe,
Ce principe permet d’éviter les problèmes de typage et de compatibilité dans le code source surtout lors d’une extension des fonctionnalités.
#### Exemple: Classe StrenghtRequirement & HealthRequirement
En plus d'être abstraite la classe a été templatisé de façons à pouvoir utiliser tout cristère d'exigence. Comme exemple deux types d'exigences ont été implémenté :
   - Un critère basé sur la classe Attribut dont les personnages dispose ou l'on teste le niveau de l'attribut.
  - Un critère basé sur la vie d'un personnage, on vérifie si le personnage un assez de vie.
  
Ces deux exigences bien qu'il sont deux différent comportement sont utilisé de la même manière grace à la templatisation.
> voir la classe [Requirement](SOLID_Exemple/include/solid_exemple_lib/requirement.h)
## Ségrégation des interfaces (Interface Segregation Principle)
#### Description
La ségrégation des interfaces définit le fait qu’une classe ne devrait pas dépendre de méthodes qu’elle n’utilise pas.
Cela permet de réduire la quantité de code inutile, ralentissant notamment la compilation. D’une manière plus générale, cela améliore la lisibilité et la maintenance du code source.
#### Exemple: Classes Smith / Dealer / Artisant
Ces classes permette de définir des types de PNJ:
- Le smith peut fabriquer et réparer
- Le dealer peut vendre
- L'artisant peut fabriquer et vendre

Dans un premier temps on pourrait créer un classe mère PNJ Interaction qui regrouperai c'est trois actions (fabriquer, réparer, vendre), mais cela donnera du code inutilisé sur les PNJ qui sont spécialisé dans certaines interactions.

Pour résoudre ce problème, des interfaces définissant chaque interaction est créée de cette manière il suffit de faire hériter un PNJ de chaques actions nécéssaire. Il sera d'autant plus facile de crée de nouvelle interactions et de nouveau PNJ avec différentes interactions.
> voir les classes [NPC Types](SOLID_Exemple/include/solid_exemple_lib/characters/npcs/npc_types.h) & [NPC Abitilites](SOLID_Exemple/include/solid_exemple_lib/characters/npcs/npc_abilities.h)
## Inversion des dépendances (Dependency Inversion Principle)
#### Description
Ce dernier principe établit que les modules de haut-niveau ne doivent pas dépendre des modules de bas-niveau. Ces modules doivent dépendre d’une abstraction.

Ce principe apporte au code source de la réutilisabilité et facilite la maintenance.

#### Exemple: Classe Requirement / RequirementValidator / StrenghtRequirement
Dans cette implémentation, requirement est l'abstraction que le module de bas-niveau, StrenghtRequirement et le module de haut niveau RequirementValidator dépende. Ces deux modules sont indépendant l'un de l'autre.
> voir la classe [Requirement](SOLID_Exemple/include/solid_exemple_lib/requirement.h)
# Reflexivité
La reflexvivité dans un programme informatique est sont aptitude à analyser et changer sa structure à sont exécution. Cela apporte plusieur avantage telle-que:
- La possibilité d'instancier un objet sans que le type d'objet sois à la compilation (codé en dur), permettant d'être changer lors de l'éxécution
- Cela offre des possibilités de débogage. Les valeurs des variables peuvent être analysées.
> voir la classe [SaveManager](SOLID_Exemple/src/save_manager.cpp)