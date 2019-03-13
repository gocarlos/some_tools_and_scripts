# contains random notes

delete all branches but master after sprint

```bash
git branch | grep -v "master" | xargs git branch -D 
```
