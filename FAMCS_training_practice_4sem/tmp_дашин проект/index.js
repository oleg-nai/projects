class Work_with_posts {
    #Posts_set = new Set();

    constructor(posts) {
        this.posts = posts;
    }

    getPosts(skip = 0, top = 10, filterConfig) {
        if (filterConfig !== undefined) {
            let result = Posts.filter(team => team.author === filterConfig.author)
            result.sort(function (a, b) {
                return new Date(b.createdAt) - new Date(a.createdAt);
            });
            return result.slice(skip, top + skip - 1);
        } else {
            Posts.sort(function (a, b) {
                return new Date(b.createdAt) - new Date(a.createdAt);
            });
            return Posts.slice(skip, top + skip);
        }
    }

    static #has_id(id) {
        for (let i = 0; i < Posts.length; i++) {
            if (id == Posts[i].id)
                return true;
        }
        return false;
    }

    getPost(id) {
        for (let i = 0; i < Posts.length; i++) {
            if (id == Posts[i].id)
                return Posts[i];
        }
        throw "Ошибка. Поста с таким id не существует";
    }

    validatePost(Object) {
        return Object.id != null && Object.descriprion != null && Object.descriprion.length < 200
            && Object.author != null && Object.createdAt != null && typeof Object.id === "string" && typeof Object.descriprion === "string"
            && typeof Object.author === "string";
    }


    addPost(Object) {
        if (this.validatePost(Object)) {
            Posts.splice(Posts.length, 0, Object);
            return true;
        } else {
            return false;
        }
    }

    removePost(id) {
        for (let i = 0; i < Posts.length; i++) {
            if (Posts[i].id === id) {
                return Posts.splice(i, 1);
            }
        }
        throw "Couldn't find object with id: " + id;
    }


    editPost(id, Post) {
        if (this.validatePost(this.getPost(id)) && Work_with_posts.#has_id(id)) {
            this.getPost(id).descriprion = Post.descriprion;
            return true;
        }
        else {
            return false;
        }
    }

    addAll(posts) {
        let result = [], k = 0;
        for (let i = 0; i < Posts.length; i++) {
            if (this.validatePost(Posts[i])) {
                this.#Posts_set.add(posts[i])
            } else {
                result[k] = Posts[i];
                k++;
            }
        }
        return result;
    }

    clear() {
        this.#Posts_set.clear();
    }

}