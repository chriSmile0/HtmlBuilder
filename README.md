# BotBuildHtml

## Objectifs 
Construire de manière très rapide une page html avec seulement des balises en entrée.  
Faire en sorte que cela soit atteignable pour tout le monde donc après on pourrais  traduire dans la langage courant donc si l'input en entrée est `liste 3 items` , on doit le correspondre en :   
`ul 3li`

## Construction 

/ `ul 3li` -> une liste de 3 items li -> :  

		<ul> 
  			<li></li>   
			<li></li>   
			<li></li>`   
		</ul>


/ `p 3 {classe1,classe2,classe3}` -> 3 paragraphes avec 3 classes différentes :   

		<p class=classe1>  
		</p`  
		<p class=classe2>  
		</p>  
		<p class=classe3>  
		</p> 


**_OU_**  
/ `p 3 classe1` -> : 

		<p class=classe1> 
		</p>  
		<p class=classe1>  
		</p>  
		<p class=classe1>  
		</p>  

On est donc ici sur de la création soit à la volée en input :   
`"ul 3li"`  
`"p 3 classe1"`  

OU avec des objets directemens : 
OBjet{ul, 3li} par exemple dans le code c++

## Modification 
Au final on sera sur la création de code objet qui stockera la ligne de chaque objet et sous-objets concernées.  
Chacun possède donc un id afin de le modifier plus tard.  
On aura donc une table de correspondance id,objet trié de manière croissante en termes de ligne.  
Chaque objet sera donc modifiable. Mais à chaque modification on est forcé de réécrire tout  le fichier , ce qui pose des problèmes donc faut mieux avoir l'idée de l'objet fini dès la première exec.

On aura donc 2 modes , celui pour construction et celui pour modfication 


## Conclusion 



