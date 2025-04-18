const CharacterStar = {
    "Aalto": 4,
    "Jianxin": 5,
    "Jiyan": 5,
    "Yangyang": 4, 
    "Calcharo": 5, 
    "Yinlin": 5, 
    "Yuanwu": 4, 
    "Chixia": 4, 
    "Encore": 5, 
    "Mortefi": 4, 
    "Baizhi": 4, 
    "Lingyang": 5, 
    "Sanhua": 4, 
    "Danjin": 4, 
    "Taoqi": 4, 
    "Verina": 5, 
    "Rover": 5,  
};

const CharacterType = {
    "Aalto": "Vent.webp",
    "Jianxin": "Vent.webp",
    "Jiyan": "Vent.webp",
    "Yangyang": "Vent.webp", 
    "Calcharo": "Dark.webp", 
    "Yinlin": "Dark.webp", 
    "Yuanwu": "Dark.webp", 
    "Chixia": "Fire.webp", 
    "Encore": "Fire.webp", 
    "Mortefi": "Fire.webp", 
    "Baizhi": "Ice.webp", 
    "Lingyang": "Ice.webp", 
    "Sanhua": "Ice.webp", 
    "Danjin": "Stone.webp", 
    "Taoqi": "Stone.webp", 
    "Verina": "Light.webp", 
    "Rover": "Light.webp",  
};

const CharacterCitation = {
    "Aalto": "Well, if it isn't my loyal patron! What do you wish to inquire about today ?",
    "Jianxin": "Release the wants, and the mind quiets. Cleanse the thoughts, and the soul clears.",
    "Jiyan": "Jiyan, Commander of Midnight Rangers. I never regret choosing to walk in the long night.",
    "Yangyang": "The wind flowed beside my ears and whispered a spellbinding story, do you wish to hear it ?", 
    "Calcharo": "Misconceptions about us abound. Violence is just one tool in our arsenal, not our sole means to an end.", 
    "Yinlin": "Green light...Green light... Red light! Good puppet. Let me think... What should be the new punishment next time I catch you sneaking? Lets find out.", 
    "Yuanwu": "Assuming I've thought my decisions through and acted with integrity, I am content.", 
    "Chixia": "Jinzhou Patroller, Chixia. You can always call on me if you ever find yourself in a pickle!", 
    "Encore": "One Sheep, two Sheep... Fifty..five.. Umm? Where was I ?", 
    "Mortefi": "Fine, since you've done this much for me... Go ahead, tell me the wildest inventions you can think of, and watch me make them happen for you", 
    "Baizhi": "No, I cannot place my faith in it, but my anticipation stems precisely from this distrust. A claim is always verifiable before it is discredited entirely.",
    "Lingyang": "Size isn't everything, you know. I may not look it, but I've got quite some strength that lets me handle any physical work no problem!", 
    "Sanhua": "Please don't stay too far away from me. I am confident to not let you get harmed in the slightest.", 
    "Danjin": "When two roses entwine, should one weep or rejoice? Hmm...? Now why would I remember this", 
    "Taoqi": "Phew... All set. Time for a little break.", 
    "Verina": "No matter how hard, I'll never give up, because it's a promise I made with mother", 
    "Rover": "Is this the beginning of a new journey? Brimming with novel sounds, and untold stories...",  
    
};

const CharacterResume = {
    "Aalto": [
        "Le gameplay d'Aalto est centré autour de sa Brume. Il la génère avec la dernière instance de son attaque normale ou en utilisant sa compétence.", 
        "Chaque tir réalisé devant votre Brume génère des Gouttes de Brume, qui régénèrent des Balles de Brume et infligent ainsi de très bons dégâts.", 
        "Sa compétence principale sert surtout à générer de la Brume et à se déplacer rapidement pour esquiver un ennemi et régénérer de l'énergie. Sans elle, le gameplay d'Aalto est très rigide."
        ],
    "Jianxin": ["Jianxin est un personnage qui demande une grande réactivité de la part du joueur, car il faut utiliser sa compétence au bon moment pour parer les attaques ennemies.",
                "En général, vous allez attaquer principalement avec votre attaque normale et parer au moment opportun.",
                "Une autre particularité de Jianxin est sa capacité à attirer les ennemis vers elle avec son ultime. Cela est intéressant car cela l'aide à faire des dégâts de zone en plus avec son Forte Circuit. Son Forte Circuit se régénère principalement grâce à sa compétence",
    ],
    "Jiyan": ["Jiyan dispose de plusieurs attaques en fonction de votre style de jeu, donc il est essentiel de comprendre le fonctionnement de son kit, qui est en fait assez simple.",
              "Ses attaques lourdes sont particulièrement utiles pour enchaîner différents combos et exploiter au mieux sa compétence aérienne. Ces attaques lourdes doivent être exécutées après une attaque normale.",
              "En outre, votre ultime doit être déclenchée lorsque votre Forte Circuit est prêt, afin de maximiser les dégâts qu'il peut infliger. Il est également recommandé de lancer votre ultime après un saut pour en augmenter l'efficacité.              "  
             ],
    "Yangyang": ["Yangyang est un personnage très utile pour rassembler les ennemis grâce à sa compétence ou son ultime.",
                 "Ensuite, vous pouvez utiliser son attaque lourde 'Chant du Vent' ou, si votre Forte Circuit est prêt, son attaque aérienne 'Libération des Plumes' pour éliminer les ennemis.",
                 "Pour activer l'attaque de son Forte Circuit, vous devez accumuler 3 échos, que vous pouvez obtenir grâce à sa compétence, son intro ou même ses attaques normales et lourdes.",
                ], 
    "Calcharo": ["Calcharo possède un mode renforcé grâce à son ultime, mais il est important de maximiser vos dégâts même lorsque vous n’avez pas votre ultime.",
                 "Pour ce faire, utilisez vos trois compétences pour augmenter les dégâts de votre transformation en accumulant des cumuls de 'Cruauté'. Cela renforcera également votre Forte Circuit.",                    
                 "Son Forte Circuit sert principalement à renforcer les attaques normales et lourdes de Calcharo lorsqu'il se transforme, lui permettant ainsi d'infliger davantage de dégâts. Par conséquent, sa compétence devient obsolète dans ce contexte, car elle ne génère plus aucun cumul de 'Cruauté'."
                ], 
    "Yinlin": ["La marionnette de Yinlin lui permet de lier les ennemis entre eux, dans le but d’infliger d'importants dégâts de zone. Sa compétence principale renforce son attaque normale :",
               "Une fois activée, elle peut être réactivée pour renforcer à nouveau l'attaque, infligeant ainsi de nouveaux dégâts de zone. Son ultime lui permet non seulement d'infliger des dégâts, mais aussi de créer des liens entre sa marionnette et les ennemis.",
               "Enfin, son Forte Circuit est son atout majeur en tant que SUBDPS et pour les dégâts de zone, car une fois déclenché, chaque ennemi lié subit des dégâts Electro à chaque attaque reçue pendant 18 secondes."
              ], 
    "Yuanwu": ["Yuanwu utilise sa compétence pour invoquer un pilier électrique nommé Cale du Tonnerre, qui demeure actif pendant 12 secondes. Ce pilier inflige des dégâts électriques à chaque attaque subie par les ennemis toutes les 1,2 secondes, dans sa zone d'effet.",
               "Son ultime améliore la résistance à l'interruption pour tous les alliés et renforce les attaques normales et lourdes de Yuanwu en lui conférant une infusion électrique.",
               "Le Forte Circuit de Yuanwu doit être activé lorsque sa compétence est prête pour infliger plus de dégâts et renforcer son infusion, tout en diminuant la résistance des monstres."
              ], 
    "Chixia": ["Le Forte Circuit de Chixia lui permet de tirer des balles en continu ou de faire un dash tout en infligeant des dégâts !",
               "Votre objectif principal est donc d'infliger un maximum de dégâts en utilisant votre compétence et votre attaque normale afin de générer des Balles Thermobarics et de mitrailler les ennemis !",
              ], 
    "Encore": ["Le gameplay d'Encore tourne entièrement autour de son ultime, qui renforce toutes ses attaques (normales, compétence, Forte Circuit, etc.) pour infliger davantage de dégâts",
               "- Sa compétence peut être utilisée deux fois : une fois à l'activation et une seconde fois à la fin de l'animation pour maximiser les dégâts.",
               "- Avec Encore, vous voulez réaliser votre 4e attaque normale pour obtenir des [Désaccord].",
               "- Votre Forte Circuit doit être utilisé avant la fin de votre ultime pour bénéficier des dégâts bonus.",
               "- Vous pouvez changer de personnage en pleine animation de votre Forte Circuit."
              ], 
    "Mortefi": ["Mortefi possède la capacité, grâce à son ultime, d'infliger des dégâts même lorsqu'il n'est pas sur le terrain.",
                "Il bénéficie grandement d'un changement de personnage, car son introduction lui génère 60 points d'“Agacement”. L'Agacement est essentiel pour recharger son Forte Circuit et lui permet de causer des dégâts importants !.", 
               ], 
    "Baizhi": ["Baizhi est une soigneuse classique, mais avec quelques particularités telles que son ultime. En plus de soigner continuellement l'équipe, il permet d'infliger des dégâts Glacio de manière continue.",
               "Son Forte Circuit est également intéressant, car il vous permet de générer de l'énergie naturellement pour votre outro en utilisant votre compétence ou une attaque lourde.",
               "Votre Outro est particulièrement intéressante car c'est la seule source de buff de son kit (sans compter l’Euphoniad à récupérer avec sa compétence)"
              ], 
    "Lingyang": ["Lingyang est un personnage qui demande aux joueurs une compréhension de ses combos. La particularité de sa compétence est qu’elle peut être lancée à n’importe quel moment de son attaque normale pour réaliser différents combos.",
                 "Si vous utilisez sa compétence à partir de sa 4e ou 5e attaque, vous allez améliorer votre compétence et régénérer votre Forte Circuit.",
                 "Le Forte Circuit de Lingyang renforce toutes ses attaques mais ne dure que 5 secondes. La seule façon de prolonger sa durée est d'utiliser votre compétence et votre ultime ! Votre ultime accorde 10 secondes supplémentaires et votre compétence 1 seconde."
                ], 
    "Sanhua": ["Votre Forte Circuit est une jauge que vous pouvez déclencher si vous utilisez votre attaque lourde au bon moment. La jauge étant assez petite, il peut être difficile de bien réussir à la synchroniser en plein combat.",
               "De ce fait, votre compétence ou votre ultime, par exemple, augmentent votre jauge, vous facilitant la tâche. Ainsi, tout le gameplay de Sanhua repose sur l’attaque lourde de celle-ci et sur sa jauge !",
              ], 
    "Danjin": ["Danjin sacrifie des PV avec sa compétence pour infliger de très bons dégâts, ce qui demande une certaine maîtrise du jeu et des esquives.",
               "À chaque utilisation de sa compétence (qui n'est pas limitée en nombre), elle génère des points pour son Forte Circuit, lui permettant ainsi de réaliser une attaque lourde dévastatrice qui vous soigne !",
               "Le but avec Danjin est donc d'utiliser sa compétence très souvent et d'exécuter une attaque chargée lorsque votre Forte Circuit est prêt."
              ], 
    "Taoqi": ["Le cœur du gameplay de Taoqi réside dans la parade offerte par son attaque lourde. Celle-ci représente une option défensive puissante ainsi qu'une opportunité offensive intéressante, car elle permet d'ignorer les mécaniques des ennemis et de poursuivre les attaques sans se soucier des esquives. Toutefois, cela nécessite une réactivité certaine, et il est important de se rappeler qu'une parade réussie restaure votre endurance.",
              "Sa compétence génère trois boucliers lors de son activation, qui peuvent vous soigner et vous protéger en cas de parade. Ces boucliers réduisent également les dégâts que vous subissez. Son ultime constitue un atout offensif notable, bien qu'il repose sur sa défense.",
              "Enfin, son Forte Circuit peut être activé si vous dépensez tous les boucliers obtenus grâce à sa compétence et que vous réalisez la quatrième attaque de son enchaînement de base, offrant ainsi une autre option offensive.",
             ], 
    "Verina": ["Verina est une excellente soigneuse grâce à son ultime et à son Forte Circuit. Mais ce n'est pas tout, elle peut également infliger des dégâts corrects pour une soigneuse tout en apportant de bons buffs avec son Outro et son talent !",
               "De plus, elle peut même empêcher un allié de mourir, ce qui en fait un personnage très polyvalent, idéal pour les débutants !"
              ], 
    "Rover": ["Le personnage principal est relativement simple à comprendre et ne possède pas de mécanique spéciale, à l'exception de son Forte Circuit.",
              "Ce dernier se régénère à chaque introduction ou attaque normale du Rover. Une fois régénéré, vous pouvez déclencher une attaque tournante en activant votre compétence. Ensuite, si vous effectuez une attaque de base, vous déclenchez une compétence dévastatrice.",          
             ],  
};

const CharacterCombo = {
    "Aalto": {"4N > C ": " Cette séquence vous permet de générer deux Brumes pour infliger davantage de dégâts et de vous déplacer plus facilement. Assurez-vous de tirer à travers les Brumes pour générer votre Forte Circuit.",
             "C > U > F > 4N": "Lorsque votre ultime est prêt et que vous avez accumulé votre Fort Circuit, utilisez cette combinaison pour anéantir l'ennemi."
            },
    "Jianxin": {"C > U > F": "En utilisant votre compétence en premier, cela vous permet de la régénérer le temps de lancer votre ultime et votre Forte Circuit. D'ailleurs en combinant ces deux, vous allez attirer les ennemis et en même temps causer des dégâts s'ils s'approchent de vous "
               },
    "Jiyan": {"5N > 1N + L > C > A > P > 2N > L > SAUT > U (Forte circuit max) > 5N":"Jiyan dispose d'une liste exhaustive de combos, donc nous ne détaillerons pas plus avant la sortie du jeu : (histoire de vous traumatiser, et il se peut qu’une erreur s’y trouve)."
             },
    "Yangyang": {"E > 1N > L > C > 1N > P (Forte Circuit) > L > 1N > U":""}, 
    "Calcharo": {"U > L > 3N > 2N > L > 3N": "", "U > L > 4N > 1N > L > 4N":"Il existe aussi des combos sans son ultime, nous attendrons la sortie du jeu pour bien détailler cela."}, 
    "Yinlin": {"3N > E > 4N > E > F > 4N": "Ce n’est qu’un simple exemple"
              }, 
    "Yuanwu": {"": "Nous détaillerons cet aspect à la sortie du jeu."}, 
    "Chixia": {"4N > C > F": "Utilisez votre Forte Circuit immédiatement après votre compétence pour annuler l'animation et maximiser les dégâts !"
              }, 
    "Encore": {"4N > C > C > U > C > 4N > F":""
              }, 
    "Mortefi": {"I > C > F > U":"Vous entrez sur le terrain et utilisez votre compétence pour accumuler suffisamment d'“Agacement” pour Mortefi. Une fois votre Forte Circuit épuisé, activez votre ultime et changez de personnage"
               }, 
    "Baizhi": {"I > U > F > C ":"En suivant cet ordre d'actions, vous allez restaurer à 100% la vie de votre équipe sans aucun souci "
              }, 
    "Lingyang": {"4N > C":"Le combo classlique à apprendre par coeur. Le personnage possède un nombre incalculable de combos… Nous détaillerons cela à la sortie du jeu."
                }, 
    "Sanhua": {"5N > F > C > F > U > F": "",
               "5N > F > C/U > F": "Le but ici est d’annuler l’animation de votre Forte Circuit"
              }, 
    "Danjin": {"":"Cette partie sera détaillée à la sortie du jeu."}, 
    "Taoqi": {"":"Cette partie sera détaillée à la sortie du jeu."}, 
    "Verina": {"I > E > F > U > O": "Une combinaison simple à utiliser pour optimiser vos rotations."}, 
    "Rover": {"":"Cette partie sera détaillée à la sortie du jeu."},  
};


const Infographique = function create(Name){
    // Création des constantes principales
    const mainDiv = document.createElement("div");
    mainDiv.classList.add("mainDiv");
    mainDiv.id = "mainDiv";
    const header = document.createElement("header");
    header.classList.add("CardDiv");
    const sectionLeft = document.createElement("section");
    sectionLeft.classList.add("LeftDiv");
    const sectionRight = document.createElement("section");
    sectionRight.classList.add("RightDiv");
    // Création de la partie gauche de l'infographique
    const articleName = document.createElement("article"); // balise qui va enveloppé tout
    articleName.classList.add("CharacterName");
    articleName.appendChild(NameDiv(Name));
    articleName.appendChild(StarDiv(Name));
    const characterIMG = document.createElement("img");
    characterIMG.classList.add("CharacterIMG");
    characterIMG.src = `./Character/${Name}/Character.png`;
    articleName.appendChild(characterIMG);
    sectionLeft.appendChild(articleName);
    // Création de la partie droite de l'infographique
    sectionRight.appendChild(Resume(Name));
    sectionRight.appendChild(Combo(Name));
    // Crétation du logo Miyoversee & Emoji
    let img = document.createElement("img");
    img.classList.add("LogoMiyoversee");
    img.src = "./res/Miyoversee.webp";
    sectionRight.appendChild(img);
    sectionRight.appendChild(Emoji());
    
    // Fin où on append tout
    header.appendChild(sectionLeft);
    header.appendChild(sectionRight);
    const bg = document.createElement("div")
    bg.classList.add("yuki");
    bg.id = "ice";
    header.appendChild(bg)
    mainDiv.appendChild(header);
    document.body.appendChild(mainDiv);
}

// LIGNE A MODIFIER POUR AFFICHER L'INFOGRAPHIQUES DU PERSONNAGE
Infographique("Aalto") // Changer juste le nom du personnage
create_snow()

// Les fonctions pour la colonne de gauches, et pour attribuer la couleur correspond au type correspondant
function NameDiv(Name){
    const NameDiv = document.createElement("div"); // Balise pour le titre et la voie du perso
    NameDiv.classList.add("Name");
    let logoIMG = document.createElement("img");
    logoIMG.classList.add("Logo");
    logoIMG.src = `./Type/${CharacterType[Name]}`;
    const root = ColorDiv(CharacterType[Name]);
    root.style.setProperty('--citation', `"${CharacterCitation[Name]}"`)     ;
    let name = document.createElement("p");
    name.innerHTML = `${Name}`;
    NameDiv.appendChild(logoIMG);
    NameDiv.appendChild(name);
    return NameDiv;
}

function ColorDiv(Type){
    const root = document.documentElement;
    if (Type == "Vent.webp"){
        root.style.setProperty('--c1', 'rgba(86, 252, 185, 1)');
        root.style.setProperty('--c2', 'rgba(86, 252, 185, 0.1)');
    }
    if (Type == "Dark.webp"){
        root.style.setProperty('--c1', 'rgba(175, 109, 229, 1)');
        root.style.setProperty('--c2', 'rgba(175, 109, 229, 0.1)');
    }
    if (Type == "Fire.webp"){
        root.style.setProperty('--c1', 'rgba(233, 114, 78, 1)');
        root.style.setProperty('--c2', 'rgba(233, 114, 78, 0.1)');
    }
    if (Type == "Ice.webp"){
        root.style.setProperty('--c1', 'rgba(168, 239, 255, 1)');
        root.style.setProperty('--c2', 'rgba(168, 239, 255, 0.1)');
    }
    if (Type == "Stone.webp"){
        root.style.setProperty('--c1', 'rgba(228, 72, 166, 1)');
        root.style.setProperty('--c2', 'rgba(228, 72, 166, 0.1)');
    }
    if (Type == "Light.webp"){
        root.style.setProperty('--c1', 'rgba(250, 229, 108, 1)');
        root.style.setProperty('--c2', 'rgba(250, 229, 108, 0.1)');
    }
    return root;
}

function StarDiv(Name){
    const StarDiv = document.createElement("div"); // Balise pour les étoiles du persos
    StarDiv.classList.add("Class");
    for (let i = 0; i < CharacterStar[Name]; i++){
        let starIMG = document.createElement("img");
        starIMG.classList.add("Logo");
        starIMG.src = "./res/star.png";
        StarDiv.appendChild(starIMG);
    }
    return StarDiv;
}

// Les fonctions pour la colonne de droite
function Resume(Name){
    const articleResume = document.createElement("article");
    articleResume.classList.add("ActiveSkills");
    let h1 = document.createElement("h1");
    h1.innerHTML = "Résumé";
    articleResume.appendChild(h1);
    const resumeDiv = document.createElement("div");
    resumeDiv.classList.add("DescriptionSkill");
    for (let i = 0; i < CharacterResume[Name].length; i++){
        let p = document.createElement("p");
        p.innerHTML = CharacterResume[Name][i];
        resumeDiv.appendChild(p);
    }
    articleResume.appendChild(resumeDiv);
    return articleResume
}

function Combo(Name){
    const articleCombo = document.createElement("article");
    articleCombo.classList.add("ActiveSkills");
    let h1 = document.createElement("h1");
    h1.innerHTML = "Combo";
    articleCombo.appendChild(h1);
    // VocabulaireDiv
    const abrev = ["N", "P", "L", "C", "U", "F", "E", "Pa", "I", "O"];
    const means = ["Attaque Normal", "Attaque Plongeante", "Attaque Lourde", "Compétence", "Ultime", "Force Circuit", "Esquive", "Parade", "Intro", "Outro"];
    const vocDiv = document.createElement("div");
    vocDiv.classList.add("VocSkill");
    for (let i = 0; i < 2; i++ ){
        let abrevDiv = document.createElement("div");
        abrevDiv.classList.add("Abrevation");
        let meansDiv = document.createElement("div");
        meansDiv.classList.add("Signification");
        for (let j = 0; j < 5; j++){
            let p1 = document.createElement("p");
            let p2 = document.createElement("p");
            p1.innerHTML = abrev[j + (i*5)];
            p2.innerHTML = means[j + (i*5)];
            abrevDiv.appendChild(p1);
            meansDiv.appendChild(p2) ;
        }
        vocDiv.appendChild(abrevDiv);
        vocDiv.appendChild(meansDiv);
    }
    articleCombo.appendChild(vocDiv)
    // ComboDiv
    const comboDiv = document.createElement("div");
    comboDiv.classList.add("DescriptionSkill");
    let i = 0;
    for (const cle in CharacterCombo[Name]){
        let comboDescription = document.createElement("div");
        comboDescription.classList.add("ComboDescription");
        
        let p1 = document.createElement("p");
        let p2 = document.createElement("p");
        p1.innerHTML = cle;
        p2.innerHTML = CharacterCombo[Name][cle];
        comboDescription.appendChild(p1);
        comboDescription.appendChild(p2);
        comboDiv.appendChild(comboDescription);
        i++;
    } 
    articleCombo.appendChild(comboDiv);
    return articleCombo
}

function Emoji(){
    const articleEmoji = document.createElement("article");
    articleEmoji.classList.add("EmojiDiv");
    // Ajout de l'emoji 
    const Emoji = ["CrapuleuxDeadInside", "CrapuleuxDumb", "CrapuleuxHappy", "CrapuleuxMad", "CrapuleuxNerd", "CrapuleuxSad"];
    let EmojiRandom = Emoji[Math.floor(Math.random() * Emoji.length)];
    const img = document.createElement("img");
    img.classList.add("Emoji");
    img.src = `./Crapuleux/${EmojiRandom}.png`;
    articleEmoji.appendChild(img);
    // Ajout du pseudo Youtube
    const divYoutube = document.createElement("div");
    divYoutube.classList.add("NameYoutube");
    const ytbIMG = document.createElement("img");
    ytbIMG.classList.add("Emoji");
    ytbIMG.src = "./res/Youtube.png";
    divYoutube.appendChild(ytbIMG);
    const p = document.createElement("p");
    p.innerHTML = "LeCrapuleux";
    divYoutube.appendChild(p);
    articleEmoji.appendChild(divYoutube);
    return articleEmoji
}
// Pour le background
function sleep(ms) {
    return new Promise(resolve => setTimeout(resolve, ms));
}

async function create_snow(){
    ice = document.getElementById("ice")
    for (let i = 0; i < 30; i++){
        var size = Math.random() * 1; 
        var left = Math.random() * 100; // Position horizontale aléatoire   
        let snow  = document.createElement("div");
        snow.classList.add("ice");
        snow.style.width = `${size}vh`;
        snow.style.height = `${size}vh`;
        snow.style.left = `${left}%`;
        snow.style.animation = "translate "+ 7 +"s linear infinite, wind "+ 7 +"s linear infinite";
        ice.appendChild(snow);
        await sleep(500);
    }
}
