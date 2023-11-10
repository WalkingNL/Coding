
struct MyCollection {
    items: [i32; 5],
}

impl IntoIterator for MyCollection {
    type Item = i32;
    type IntoIter = std::array::IntoIter<i32, 5>;

    fn into_iter(self) -> Self::IntoIter {
        self.items.into_iter()
        // std::array::IntoIter::new(self.items)
    }
}

fn main() {
    let collection = MyCollection {
        items: [1, 2, 3, 4, 5],
    };

    for item in collection {
        println!("{}", item);
    }
}

// struct MyCollection {
//     items: [i32; 5],
// }

// impl<'a> IntoIterator for &'a MyCollection {
//     type Item = &'a i32;
//     type IntoIter = std::slice::Iter<'a, i32>;

//     fn into_iter(self) -> Self::IntoIter {
//         self.items.iter()
//     }
// }

// fn main() {
//     let collection = MyCollection {
//         items: [1, 2, 3, 4, 5],
//     };

//     for item in &collection {
//         println!("{}", item);
//     }
// }


