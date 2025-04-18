let CurrentMoleTile = "";
let CurrentPlantTile = "";
let score = 0;
let Game = true;
window.onload = ()=>{
    SetGame();
}

function SetGame(){
    const Container = document.getElementById("whackContainer");
    for(let i = 0; i < 9; i++){
        const Mole = document.createElement("div");
        Mole.id = i.toString();
        Mole.addEventListener("click", SelectTile);
        Container.appendChild(Mole);
    }

    setInterval(SetMole, 1000);
    setInterval(SetPlant, 2000);
}

function SelectTile(){
    if(!Game){return;}
    if(this == CurrentMoleTile){
        const ScoreSpan = document.getElementById("scoreValue");
        score += 10;
        ScoreSpan.innerHTML = score.toString();
    }
    else if(this == CurrentPlantTile){
        const Message_endGame = document.getElementById('score_message');
        Message_endGame.innerHTML = "Game over : ";
        Game = false;
    }
}
function GenerateRandomNumber(){
    const num = Math.floor(Math.random()*9);
    return num.toString();
}
function SetMole(){
    if(!Game){return;}
    let Mole = document.createElement("img");
    Mole.src = "images/monty-mole.png";
    const num = GenerateRandomNumber();
    if(CurrentMoleTile){
        CurrentMoleTile.innerHTML = "";
    }
    if(CurrentPlantTile && num === CurrentPlantTile.id){
        return;
    }
    CurrentMoleTile = document.getElementById(num);
    CurrentMoleTile.appendChild(Mole);}


function SetPlant(){
    if(!Game){return;}
    let Plant = document.createElement("img");
    Plant.src = "images/piranha-plant.png";
    const num = GenerateRandomNumber();
    if(CurrentPlantTile){
        CurrentPlantTile.innerHTML = "";
    }

    if(CurrentMoleTile && num === CurrentMoleTile.id){
        return;
    }
    CurrentPlantTile = document.getElementById(num);
    CurrentPlantTile.appendChild(Plant);
}