question 1:
```
To https://github.com/WalkingNL/encryption-currency.git
 ! [rejected]        main -> main (fetch first)
error: failed to push some refs to 'https://github.com/WalkingNL/encryption-currency.git'
hint: Updates were rejected because the remote contains work that you do
hint: not have locally. This is usually caused by another repository pushing
hint: to the same ref. You may want to first integrate the remote changes
hint: (e.g., 'git pull ...') before pushing again.
hint: See the 'Note about fast-forwards' in 'git push --help' for details.
```
**answer**: The error message you're encountering is a common issue in Git when trying to push commits to a repository while the remote repository has changes that you do not have locally. This situation typically occurs when another user has pushed to the same branch of the repository after your last pull or clone. Let's walk through how to resolve this issue step-by-step.

### Error Explanation

- **Error:** `! [rejected] main -> main (fetch first)`
- **Meaning:** Your push to the `main` branch has been rejected because your local branch is behind its remote counterpart. This means there are commits on the remote `main` branch that you do not have locally.

### Step-by-Step Solution

**Step 1: Fetch and Review the Changes**
- First, you should fetch the latest changes from the remote repository without merging them into your local branch. This allows you to review the changes before integrating them.
  ```bash
  git fetch origin
  ```

- Compare your local branch with the remote branch:
  ```bash
  git log --oneline --decorate --graph --all
  ```

**Step 2: Decide on Integration Method**

You have a couple of options on how to integrate these changes: merging or rebasing. Here’s how to decide:
- **Merge:** This will create a new commit in your history that merges the changes from the remote `main` branch to your local `main` branch.
- **Rebase:** This will rewrite your local branch's changes on top of the remote branch's latest commit.

**Step 3: Merge the Changes**
If you choose to merge, you will pull the changes and merge them:
```bash
git pull origin main
```
or explicitly merge:
```bash
git merge origin/main
```
This command creates a new "merge commit" in your history, which shows that you have integrated the changes from the remote `main` branch.

**Step 4: Rebase the Changes**
If you prefer a cleaner project history or need to ensure your changes are placed on top of the latest remote changes, you may choose to rebase:
```bash
git pull --rebase origin main
```
or:
```bash
git rebase origin/main
```
Rebasing will re-apply your work on top of what is already on `main`, as if your changes were made after the latest changes on `main`.

**Step 5: Push Your Changes**
After integrating the remote changes by either merging or rebasing, you should be able to push your local changes to the remote repository:
```bash
git push origin main
```

### Additional Tips

- **Handling Conflicts:** If you encounter conflicts during the merge or rebase, Git will stop and ask you to resolve the conflicts. You need to open the conflicting files and make the necessary changes.
- **After Resolving Conflicts:**
  - If you were merging, add the resolved files (`git add <file>`), and then complete the merge with `git merge --continue`.
  - If you were rebasing, add the resolved files (`git add <file>`) and continue rebasing with `git rebase --continue`.

- **Using Graphical Tools:** If you prefer a GUI over the command line, tools like GitKraken, SourceTree, or the GitHub Desktop can provide a visual interface to handle pulls, merges, rebases, and conflict resolution.

**Final Note:** Always communicate with your team when performing operations that affect the shared repository (like `rebase`), as these can complicate the project history for others.

By following these steps, you should be able to successfully integrate the remote changes and continue with your work. Remember, regular pulls from the remote repository can help minimize these issues.

---
```
  git checkout -b qabil_test_branch
```
Note: create and switch to new branch `qabil_test_branch`, this new branch is a local branch currently.

```
git push -u origin qabil_test_branch
```
Note: push the new branch `qabil_test_branch` to remote base.


