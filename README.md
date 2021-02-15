# SOLID C++ RPG Implementation
SOLID regroupe cinq principes de conception permettant de produire des architectures plus compréhensibles, flexibles et de faciliter leurs maintenances.
## Responsabilité Unique (Single Responsibility Principle)
#### Description
Une classe doit avoir uniquement une seule responsabilité. Si l’on doit modifier cette classe, cela doit être dans l’unique but de modifier le comportement de cette classe.
En respectant cette règle, cela rend le code source plus facile à comprendre et à maintenir.

#### Exemple: Classes World & SaveManager
On pourrait ajouter une fonction de sauvegarde à la classe World, mais cela violerai le principe de responsabilité unique.
La classe World doit uniquement être responsable du fonctionnement de la simulation si l'on souhaite ajouter une fonction pour sauvegarder créer un classe qui sera responsable de sauvegarder l'état du monde.
> voir les classes [World](SOLID_Exemple/include/solid_exemple_lib/world.h) & [SaveManager](SOLID_Exemple/include/solid_exemple_lib/save_manager.h)
## Ouvert / Fermé (Open/Close Principle)
#### Description
Ce principe défini qu’un programme doit être ouvert à l'extension, mais fermé à la modification. En d’autres termes	 si l’application est amenée à étendre ses fonctionnalités, cela doit se faire par une extension du code source et non par sa modification.

Une fois qu’une classe est approuvée via des revues de code et des tests unitaires, elle ne doit plus être modifiée.
Ce principe permet de rendre le code source plus flexible et de diminuer les dépendances.

#### Exemple: Classe Requirement
Cette classe est abstraite, elle à été implémentée pour permettre l'ajout de futur exigence. Les classes étendue de la classe abstraite doivent définir le comportement de leurs méthodes afin de créer de nouvelles exigences.
> voir la classe [Requirement](SOLID_Exemple/include/solid_exemple_lib/requirement.h)
## Substitution de Liskov (Liskov Substitution Principle)
#### Description
Le principe de substitution de Liskov évoque la notion de sous-type. Pour tout sous type d’une classe,
Ce principe permet d’éviter les problèmes de typage et de compatibilité dans le code source surtout lors d’une extension des fonctionnalités.
#### Exemple: Classe StrenghtRequirement & HealthRequirement
En plus d'être abstraite la classe a été templatisé de façons à pouvoir utiliser tout cristère d'exigence. Comme exemple deux types d'exigences ont été implémentés :
 - Un critère basé sur la classe Attribut dont les personnages dispose ou l'on teste le niveau de l'attribut.
 - Un critère basé sur la vie d'un personnage, on vérifie si le personnage un assez de vie.
  
Ces deux exigences bien qu'elles soient deux différents comportements sont utilisés de la même manière grâce à la templatisation.
> voir la classe [Requirement](SOLID_Exemple/include/solid_exemple_lib/requirement.h)
## Ségrégation des interfaces (Interface Segregation Principle)
#### Description
La ségrégation des interfaces définit le fait qu’une classe ne devrait pas dépendre de méthodes qu’elle n’utilise pas.
Cela permet de réduire la quantité de code inutile, ralentissant notamment la compilation. D’une manière plus générale, cela améliore la lisibilité et la maintenance du code source.
#### Exemple: Classes Smith / Dealer / Artisant
Ces classes permettent de définir des types de PNJ:
- Le smith peut fabriquer et réparer
- Le dealer peut vendre
- L'artisant peut fabriquer et vendre

Dans un premier temps on pourrait créer une classe mère PNJ Interaction qui regrouperai c'est trois actions (fabriquer, réparer, vendre), mais cela donnera du code inutilisé sur les PNJ qui sont spécialisés dans certaines interactions.

Pour résoudre ce problème, des interfaces définissant chaque interaction est créée de cette manière il suffit de faire hériter un PNJ de chaque action nécéssaires. Il sera d'autant plus facile de créer de nouvelles interactions et de nouveau PNJ avec différentes interactions.
> voir les classes [NPC Types](SOLID_Exemple/include/solid_exemple_lib/characters/npcs/npc_types.h) & [NPC Abitilites](SOLID_Exemple/include/solid_exemple_lib/characters/npcs/npc_abilities.h)
## Inversion des dépendances (Dependency Inversion Principle)
#### Description
Ce dernier principe établit que les modules de haut-niveau ne doivent pas dépendre des modules de bas-niveau. Ces modules doivent dépendre d’une abstraction.

Ce principe apporte au code source de la réutilisabilité et facilite la maintenance.

#### Exemple: Classe Requirement / RequirementValidator / StrenghtRequirement
Dans cette implémentation, requirement est l'abstraction que le module de bas-niveau, StrenghtRequirement et le module de haut niveau RequirementValidator dépende. Ces deux modules sont indépendants l'un de l'autre.
> voir la classe [Requirement](SOLID_Exemple/include/solid_exemple_lib/requirement.h)
# Reflexivité
La reflexivité dans un programme informatique est son aptitude à analyser et changer sa structure à sont exécution. Cela apporte plusieurs avantage telle-que:
- La possibilité d'instancier un objet sans que le type d'objet sois à la compilation (codé en dur), permettant d'être changé lors de l'éxécution
- Cela offre des possibilités de débogage. Les valeurs des variables peuvent être analysées.
#### Exemple: Classe SaveManager
Dans chaque entité de cette implémentation (World, Character, Attribute) sont analysés grâce à la macro "REFLECT" et le contenu peut être inspecté à tout moment.
> voir la classe [SaveManager](SOLID_Exemple/src/save_manager.cpp#L30)
>> Le code est basé sur le développement de 
> Auteur: Jeff Pershing
> Source: https://github.com/preshing/FlexibleReflection
> voir [Reflect.h](SOLID_Exemple/include/reflect.h) & [Primitives.cpp](SOLID_Exemple/src/primitives.cpp)