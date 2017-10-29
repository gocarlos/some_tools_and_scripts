## Clear git history brute force

# 0.  
git clone <url>

# 1. 
rm -rf .git

# 2

git init
git add .
git commit -m "Initial commit"

# 3:

git remote add origin <uri>
git push -u --force origin master


# TODO
# * [ ] Make a script our of this.  
