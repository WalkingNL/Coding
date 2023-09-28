// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
// 
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }

struct Solution;

impl Solution {
    pub fn add_two_numbers(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
            
        let mut l1 = l1;
        let mut l2 = l2;
        let mut carry = 0;
        let mut sum = 0;
        let mut result = Some(Box::new(ListNode::new(0)));
        let mut current = &mut result;

        while l1.is_some() || l2.is_some() {
            sum = carry;
            if let Some(l1_node) = l1 {
                sum += l1_node.val;
                l1 = l1_node.next;
            }
            if let Some(l2_node) = l2 {
                sum += l2_node.val;
                l2 = l2_node.next;
            }
            carry = sum / 10;
            sum = sum % 10;
            if let Some(current_node) = current {
                current_node.next = Some(Box::new(ListNode::new(sum)));
                current = &mut current_node.next;
            }
        }

        if carry > 0 {
            if let Some(current_node) = current {
                current_node.next = Some(Box::new(ListNode::new(carry)));
            }
        }

        result.unwrap().next
    }
}

fn main() {

    l1 = ListNode::new(2);
    l1.next = ListNode::new(4);
    l1.next.next = ListNode::new(3);

    l2 = ListNode::new(5);
    l2.next = ListNode::new(6);
    l2.next.next = ListNode::new(4);

    Solution::add_two_numbers(l1, l2);
}
