// alert("heelloo")



var Posts = [
    {
        id: "1",
        descrption: "",
        createAt: "23.03.2021, 10.00",
        author: "Oleg Nai",
        photolink: "http://asdf//asdf//asdf",
    },
    {
        id: "2",
        descrption: "asdfasdf",
        createAt: "23.03.2021, 10.00",
        author: "Oleg Nai",
        photolink: "http://asdf//asdf//asdf",
    },
    {
        id: "3",
        descrption: "asdfasdf",
        createAt: "23.03.2021, 10.00",
        author: "Oleg Nai",
        photolink: "http://asdf//asdf//asdf",
    }
    {
        id: "4",
        descrption: "asdfasdf",
        createAt: "23.03.2021, 10.00",
        author: "Oleg Nai",
        photolink: "http://asdf//asdf//asdf",
    }
]


// ======================================================
// работа с функциями


function changeColor(newColor) {
    var element = document.getElementById("text");
    element.style.color = newColor;
}


// ======================================================
// создание объектов

    var apple = new Object();
    apple.color = "green";
    apple.shape = "round";

    apple.discribe = function() {
        return "An apple has " + this.color; 
    }

    console.log(apple.discribe());



var persom = {
    firstName: "oleg",
    age: 18,
    children: ["11", "22"],
    adress: {
        street: "asdfasdfasdf",
        city: "minsk"
    },
    Name: function() {
        return this.firstName + " , age is = " + this.age;
    }
}

// console.log(persom.Name());

// ======================================================
// функции

// function summ (a,b) {
//     return a + b
// }

// console.log(summ(2,3));



// ======================================================
// циклы

// for(var i = 100; i >=10; i--) {
//     console.log(i);
// }


// var mas = ["asdf", "ds", "green"];
// for(var i = 0; i < mas.length; i++){
//     console.log(mas[i]);
// }
// console.log("====");



// ======================================================
// массивы

// var first = 12;
// var second = 24;

// var asd = [1,2,3,4];
// var asd_1 = new Array (1,2,3,4,5)
// asd.push("hello, i am new one")

// console.log(asd[4]);


// document.write("result of concat: " + first + second);
// document.write("result of summing: ", first + second);


// // ======================================================
// работа с переменными
/*
var num = 23;
var Num = 13;

var name = prompt("what is your name?");
console.log("your name is: " + name);

console.log("hello")
*/


