let BoardWidth = 360;
let BoardHieght = 640;
let context;
let birdWidth = 34;
let birdheight = 24;
let BirdX = BoardWidth / 8;
let BirdY = BoardHieght / 2;
let Bird = {
    x: BirdX, 
    y: BirdY, 
    width: birdWidth, 
    height: birdheight
}
const OpeningSpace = BoardHieght / 4;
let  Pipes = [];

let PipeWidth = 64;
let PipeHeight = 512;
let PipeX = BoardWidth - PipeWidth;
let PipeY = 0;
let PipeVelocity = -2;
let TopPipeImg;
let BottomPipeImg;
let GameOver = false;
let VitesseY = 0;
let gravity = 0.4;
const BirdImg = new Image();
BirdImg.src = "./images/flappybird.png";
let score = 0;

window.onload = ()=>{
    const board = document.getElementById("Board");
    board.width = BoardWidth;
    board.height = BoardHieght;
    context = board.getContext("2d");   
    BirdImg.onload = ()=>{
        context.drawImage(BirdImg, Bird.x, Bird.y, Bird.width, Bird.height);
    }
    TopPipeImg = new Image();
    TopPipeImg.src = "./images/toppipe.png";
    BottomPipeImg = new Image();
    BottomPipeImg.src = "./images/bottompipe.png";
    setInterval(PlacePipes, 1500);
    requestAnimationFrame(Update);
}


function Update(){
    window.addEventListener("keyup", Jump);
    requestAnimationFrame(Update);
    if(GameOver){
        return;
    }
    context.clearRect(0, 0, BoardWidth, BoardHieght);
    for(let i = 0; i< Pipes.length ; i++){
        let pipe = Pipes[i];
        if(collision(Bird, pipe)){
            GameOver = true;
        }
        else if(!pipe.passed && Bird.x > pipe.x + pipe.width){
            score += 0.5;
            pipe.passed = true;
        }
        pipe.x += PipeVelocity;
        context.drawImage(pipe.img, pipe.x, pipe.y, pipe.width, pipe.height);
    }
    VitesseY += gravity;
    Bird.y += VitesseY;
    CollisionWithBoard(Bird);
    Bird.y = Math.max(Bird.y, birdheight);
    context.drawImage(BirdImg, Bird.x, Bird.y, Bird.width, Bird.height);
    context.font = " 30px Arial sans-serif";
    context.font
    context.fillStyle = "grey";
    context.fillText(`Score : ${score}`, 30, 100);
    if(GameOver){
        context.fillText("Game Over ...", BoardWidth/2 - 100, BoardHieght/2);
    }
}
function IncrementScore(bird, pipe){
    
}

function collision(Bird, Pipe){
    return Bird.x < Pipe.x + Pipe.width &&
            Bird.x + Bird.width > Pipe.x &&
            Bird.y < Pipe.y + Pipe.height &&
            Bird.y + Bird.height > Pipe.y;
}
function PlacePipes(){
    if(GameOver){
        return;
    }
    let PipeRandom =  PipeY - PipeHeight / 4 - PipeHeight / 2 * Math.random();
    let TopPipe = {
        img: TopPipeImg, 
        x: PipeX, 
        y: PipeRandom, 
        width: PipeWidth, 
        height: PipeHeight, 
        passed: false
    }
    let BottomPipe = {
        img: BottomPipeImg, 
        x: PipeX, 
        y: PipeRandom + PipeHeight + OpeningSpace, 
        width: PipeWidth, 
        height: PipeHeight, 
        passed: false
    }
    Pipes.push(BottomPipe);
    Pipes.push(TopPipe);
}
function Jump(e){
    if(e.code == "Space"){
        VitesseY = -6;
        if(GameOver){
            console.log("hhh");
            Bird.x = BirdX;
            Bird.y = BirdY;
            VitesseY = 0;
            score = 0;
            Pipes = [];
            GameOver = false;
        }
    }
}
function CollisionWithBoard(bird){
    if(bird.y > BoardHieght){
        GameOver = true;
    }
}