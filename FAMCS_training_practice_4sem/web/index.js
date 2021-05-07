var posts = [
    {
        id: "1",
        tag: "computers",
        name: "Mac Book",
        descrption: "Macbook is the best in the world",
        createAt: new Date('December 17, 1995 03:24:00'),
        author: "Oleg-Nai",
        photolink: "https://store.storeimages.cdn-apple.com/4982/as-images.apple.com/is/macbook-air-gold-select-201810?wid=892&hei=820&&qlt=80&.v=1603332211000",
        price: 100
    },
    {
        id: "2",
        tag: "phones",
        descrption: "Iphone is the best in the world",
        name: "Iphone",
        createAt: new Date('December 17, 1995 03:24:00'),
        author: "Kirill",
        photolink: "http://pngimg.com/uploads/iphone_12/iphone_12_PNG19.png",
        price: 523
    },
    {
        id: "3",
        tag: "airpods",
        descrption: "Airpods is the best in the world",
        name: "Airpods",
        createAt: new Date('December 17, 1995 03:24:00'),
        author: "Maxim",
        photolink: "https://store.storeimages.cdn-apple.com/4668/as-images.apple.com/is/MWP22?wid=1144&hei=1144&fmt=jpeg&qlt=80&op_usm=0.5,0.5&.v=1591634795000",
        price: 523

    },
    {
        id: "4",
        tag: "ipads",
        descrption: "Ipad is the best in the world",
        name: "Ipad",
        createAt: new Date('December 17, 1995 03:24:00'),
        author: "Andrey",
        photolink: "https://www.ferra.ru/thumb/1800x0/filters:quality(75):no_upscale()/imgs/2021/03/14/09/4559770/b6431d85c015a464b3ddd6420bf120782ee20b64.png",
        price: 523
    },
    {
        id: "5",
        tag: "computers",
        name: "Mac Book",
        descrption: "Macbook is the best in the world",
        createAt: new Date('December 17, 1995 03:24:00'),
        author: "Oleg-Nai",
        photolink: "https://store.storeimages.cdn-apple.com/4982/as-images.apple.com/is/macbook-air-gold-select-201810?wid=892&hei=820&&qlt=80&.v=1603332211000",
        price: 100
    },
    {
        id: "6",
        tag: "phones",
        descrption: "Iphone is the best in the world",
        name: "Iphone",
        createAt: new Date('December 17, 1995 03:24:00'),
        author: "Kirill",
        photolink: "http://pngimg.com/uploads/iphone_12/iphone_12_PNG19.png",
        price: 523
    },
    {
        id: "7",
        tag: "airpods",
        descrption: "Airpods is the best in the world",
        name: "Airpods",
        createAt: new Date('December 17, 1995 03:24:00'),
        author: "Maxim",
        photolink: "https://store.storeimages.cdn-apple.com/4668/as-images.apple.com/is/MWP22?wid=1144&hei=1144&fmt=jpeg&qlt=80&op_usm=0.5,0.5&.v=1591634795000",
        price: 523

    },
    {
        id: "8",
        tag: "ipads",
        descrption: "Ipad is the best in the world",
        name: "Ipad",
        createAt: new Date('December 17, 1995 03:24:00'),
        author: "Andrey",
        photolink: "https://www.ferra.ru/thumb/1800x0/filters:quality(75):no_upscale()/imgs/2021/03/14/09/4559770/b6431d85c015a464b3ddd6420bf120782ee20b64.png",
        price: 523
    }
]

class Posts {

    constructor(posts) {
        this.posts = posts;
    }

    printProduct(data) {
        div_element.innerHTML = "";
        data.forEach((product, ind) => {
            div_element.innerHTML +=`
    <div class="col-lg-3 col-md-6 mb-4">
    <div class = "card">
    <div class="view overlay">
    <img src = ${product.photolink} alt="" class = "card-img-top">
    
    </div>
    <div class="card-body text-center">
    
    <a href="#" class="grey-text">
    <h5> ${product.name}</h5>
    </a>
    
      <h5>
            <strong>
              <a href="#" class="dark-grey-text">${product.descrption}</a>
            </strong>
      </h5>
    
    
      <h4 class="fond-weight-bold blue-text">
        ${product.price} $ 
      </h4>
    
    
      <h5 class="grey-text">
        ${product.author}
      </h5>
    
      <h5 class="grey-text">
        ${product.createAt}
      </h5>
    
    </div>
    </div>
    </div>
        `
        });
    }
    
    // сортировка по тегу и дате 
    getPosts(filterConfig = "Date", skip = 0, top = this.posts.length) {
        if (filterConfig == "Date") {
            this.posts.sort(function (a, b) {
                return new Date(b.createdAt) - new Date(a.createdAt);
            });
            return this.posts.slice(skip, top + skip);
        }
        else if (filterConfig == "computers") {
            var temp = []
            this.posts.forEach((product, ind) => {
                if (product.tag == "computers"){
                    temp.push(product)
                }
            }); 
            return temp
        }
        else if (filterConfig == "phones") {
            var temp = []
            this.posts.forEach((product, ind) => {
                if (product.tag == "phones"){
                    temp.push(product)
                }
            }); 
            return temp
        }
        else if (filterConfig == "airpods") {
            var temp = []
            this.posts.forEach((product, ind) => {
                if (product.tag == "airpods"){
                    temp.push(product)
                }
            }); 
            return temp
        }
        else if (filterConfig == "ipads") {
            var temp = []
            this.posts.forEach((product, ind) => {
                if (product.tag == "ipads"){
                    temp.push(product)
                }
            }); 
            return temp
        }
        else {
            throw "Error. there is no such filter";
        }
    }

    getPost(id) {
        for (let i = 0; i < this.posts.length; i++) {
            if (id == this.posts[i].id)
                return this.posts[i];
        }
        throw "Error. There is no such id";
    }

    addPost(Object) {
        if (this.validatePost(Object)) {
            this.posts.splice(this.posts.length, 0, Object);
            return true;
        } else {
            return false;
        }
    }

    removePost(id) {
        for (let i = 0; i <  this.posts.length; i++) {
            if ( this.posts[i].id === id) {
                return this.posts.splice(i, 1);
            }
        }
        throw "Couldn't find object with id: " + id;
    }

    validatePost(Object) {
        return Object.id != null && Object.name != null && Object.descrption.length < 200 &&
            Object.author != null && Object.price != null; 
    }
    

    // editPost(id, Post) {
    //     if (this.validatePost(this.getPost(id)) && Work_with_posts.#has_id(id)) {
    //         this.getPost(id).descriprion = Post.descriprion;
    //         return true;
    //     }
    //     else {
    //         return false;
    //     }
    // }

    //     addAll(posts) {
    //     let result = [], k = 0;
    //     for (let i = 0; i < Posts.length; i++) {
    //         if (this.validatePost(Posts[i])) {
    //             this.#Posts_set.add(posts[i])
    //         } else {
    //             result[k] = Posts[i];
    //             k++;
    //         }
    //     }
    //     return result;
    // }

}

a = new Posts(posts);

// console.log(a.getPosts('computers'))
// console.log(a.getPosts('phones'))
// console.log(a.getPosts('ipads'))
// console.log(a.getPosts('airpods'))


// console.log(a.printProduct(a.getPosts('computers', 0, 2)))



// console.log("test getPost: ")
// console.log(a.getPost(3))


// test_true = {
//     id: "15",
//     name: "LLKSAJDFLKASJDFOIAJSDFOIJ",
//     descrption: "Macbook is the best in the world",
//     createAt: new Date('December 17, 1995 03:24:00'),
//     author: "Oleg-Nai",
//     photolink: "https://store.storeimages.cdn-apple.com/4982/as-images.apple.com/is/macbook-air-gold-select-201810?wid=892&hei=820&&qlt=80&.v=1603332211000",
//     price: 100
// }
// test_false = {
//     descrption: "",
//     createAt: new Date('December 17, 1995 03:24:00'),
//     author: "Oleg-Nai",
//     photolink: "https://store.storeimages.cdn-apple.com/4982/as-images.apple.com/is/macbook-air-gold-select-201810?wid=892&hei=820&&qlt=80&.v=1603332211000",
//     price: 100
// }



// console.log("test true validatePost: ")
// console.log(a.validatePost(test_true))

// console.log("test false validatePost: ")
// console.log(a.validatePost(test_false))


// console.log("test addPost: ")
// console.log(a.addPost(test_true))

// console.log("test removePost: ")
// console.log(a.removePost("4"))


// console.log("output all posts: ")

// console.log(a.getPosts("Date"))





// function printProduct() {
//     posts.forEach((product, ind) => {
//         document.write(`
// <div class="col-lg-3 col-md-6 mb-4">
// <div class = "card">
// <div class="view overlay">
// <img src = ${product.photolink} alt="" class = "card-img-top">

// </div>
// <div class="card-body text-center">

// <a href="#" class="grey-text">
// <h5> ${product.name}</h5>
// </a>

//   <h5>
//         <strong>
//           <a href="#" class="dark-grey-text">${product.descrption}</a>
//         </strong>
//   </h5>


//   <h4 class="fond-weight-bold blue-text">
//     ${product.price} $ 
//   </h4>


//   <h5 class="grey-text">
//     ${product.author}
//   </h5>


//   <h5 class="grey-text">
//     ${product.createAt}
//   </h5>

// </div>
// </div>
// </div>
//     `)
//     });
//     document.write(`</div></div>`);
// }


























/*
// alert("heelloo")

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
