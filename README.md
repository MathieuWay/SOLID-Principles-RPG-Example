# SOLID C++ RPG Implementation
SOLID regroupe 5 principes de conception permettant de produire des architectures plus compr�hensibles, flexibles et de faciliter leurs maintenances.
## Responsabilit� Unique (Single Responsibility Principle)
#### Description
Une classe doit avoir uniquement une seule responsabilit�. Si l�on doit modifier cette classe, cela doit �tre dans l�unique but de modifier le comportement de cette classe.
En respectant cette r�gle, cela rend le code source plus facile � comprendre et � maintenir.

#### Exemple: Classes World & SaveManager
On pourrait ajouter une fonction de sauvegarde � la classe World mais cela violerai le principe de responsabilit� unique.
La classe World doit uniquement �tre responsable du fonctionnement de la simulation si l'on souhaite ajouter une fonction pour sauvegarder cr�er un classe qui sera responsable de sauvegarder l'�tat du monde.
> voir les classes [World](SOLID_Exemple/include/solid_exemple_lib/world.h) & [SaveManager](SOLID_Exemple/include/solid_exemple_lib/save_manager.h)
## Ouvert / Ferm� (Open/Close Principle)
#### Description
Ce principe d�fini qu�un programme doit �tre ouvert � l'extension mais ferm� � la modification. En d�autre terme si l�application est amen�e � �tendre ses fonctionnalit�s, cela doit se faire par une extension du code source et non par sa modification.

Une fois qu�une classe est approuv�e via des revues de code et des tests unitaires, elle ne doit plus �tre modifi�e.
Ce principe permet de rendre le code source plus flexible et de diminuer les d�pendances.

#### Exemple: Classe Requirement
Cette classe est abstraite, elle � �t� impl�ment� pour permettre l'ajout de futur exigence. Les classe �tendue de la classe abstraite doivent d�finir le comportement de leurs m�thodes afin de cr�e de nouvelle exigence.
> voir la classe [Requirement](SOLID_Exemple/include/solid_exemple_lib/requirement.h)
## Substitution de Liskov (Liskov Substitution Principle)
#### Description
Le principe de substitution de Liskov �voque la notion de sous-type. Pour tout sous type d�une classe,
Ce principe permet d��viter les probl�mes de typage et de compatibilit� dans le code source surtout lors d�une extension des fonctionnalit�s.
#### Exemple: Classe StrenghtRequirement & HealthRequirement
En plus d'�tre abstraite la classe a �t� templatis� de fa�ons � pouvoir utiliser tout crist�re d'exigence. Comme exemple deux types d'exigences ont �t� impl�ment� :
   - Un crit�re bas� sur la classe Attribut dont les personnages dispose ou l'on teste le niveau de l'attribut.
  - Un crit�re bas� sur la vie d'un personnage, on v�rifie si le personnage un assez de vie.
  
Ces deux exigences bien qu'il sont deux diff�rent comportement sont utilis� de la m�me mani�re grace � la templatisation.
> voir la classe [Requirement](SOLID_Exemple/include/solid_exemple_lib/requirement.h)
## S�gr�gation des interfaces (Interface Segregation Principle)
#### Description
La s�gr�gation des interfaces d�finit le fait qu�une classe ne devrait pas d�pendre de m�thodes qu�elle n�utilise pas.
Cela permet de r�duire la quantit� de code inutile, ralentissant notamment la compilation. D�une mani�re plus g�n�rale, cela am�liore la lisibilit� et la maintenance du code source.
#### Exemple: Classes Smith / Dealer / Artisant
Ces classes permette de d�finir des types de PNJ:
- Le smith peut fabriquer et r�parer
- Le dealer peut vendre
- L'artisant peut fabriquer et vendre

Dans un premier temps on pourrait cr�er un classe m�re PNJ Interaction qui regrouperai c'est trois actions (fabriquer, r�parer, vendre), mais cela donnera du code inutilis� sur les PNJ qui sont sp�cialis� dans certaines interactions.

Pour r�soudre ce probl�me, des interfaces d�finissant chaque interaction est cr��e de cette mani�re il suffit de faire h�riter un PNJ de chaques actions n�c�ssaire. Il sera d'autant plus facile de cr�e de nouvelle interactions et de nouveau PNJ avec diff�rentes interactions.
> voir les classes [NPC Types](SOLID_Exemple/include/solid_exemple_lib/characters/npcs/npc_types.h) & [NPC Abitilites](SOLID_Exemple/include/solid_exemple_lib/characters/npcs/npc_abilities.h)
## Inversion des d�pendances (Dependency Inversion Principle)
#### Description
Ce dernier principe �tablit que les modules de haut-niveau ne doivent pas d�pendre des modules de bas-niveau. Ces modules doivent d�pendre d�une abstraction.

Ce principe apporte au code source de la r�utilisabilit� et facilite la maintenance.

#### Exemple: Classe Requirement / RequirementValidator / StrenghtRequirement
Dans cette impl�mentation, requirement est l'abstraction que le module de bas-niveau, StrenghtRequirement et le module de haut niveau RequirementValidator d�pende. Ces deux modules sont ind�pendant l'un de l'autre.
> voir la classe [Requirement](SOLID_Exemple/include/solid_exemple_lib/requirement.h)
# Reflexivit�
La reflexvivit� dans un programme informatique est sont aptitude � analyser et changer sa structure � sont ex�cution. Cela apporte plusieur avantage telle-que:
- La possibilit� d'instancier un objet sans que le type d'objet sois � la compilation (cod� en dur), permettant d'�tre changer lors de l'�x�cution
- Cela offre des possibilit�s de d�bogage. Les valeurs des variables peuvent �tre analys�es.
> voir la classe [SaveManager](SOLID_Exemple/src/save_manager.cpp)