# If you come from bash you might have to change your $PATH.
# export PATH=$HOME/bin:/usr/local/bin:$PATH

# Path to your oh-my-zsh installation.
export ZSH="/Users/bafraiki/.oh-my-zsh"

# Set name of the theme to load --- if set to "random", it will
# load a random theme each time oh-my-zsh is loaded, in which case,
# to know which specific one was loaded, run: echo $RANDOM_THEME
# See https://github.com/robbyrussell/oh-my-zsh/wiki/Themes
ZSH_THEME="robbyrussell"

# Set list of themes to pick from when loading at random
# Setting this variable when ZSH_THEME=random will cause zsh to load
# a theme from this variable instead of looking in ~/.oh-my-zsh/themes/
# If set to an empty array, this variable will have no effect.
# ZSH_THEME_RANDOM_CANDIDATES=( "robbyrussell" "agnoster" )

# Uncomment the following line to use case-sensitive completion.
# CASE_SENSITIVE="true"

# Uncomment the following line to use hyphen-insensitive completion.
# Case-sensitive completion must be off. _ and - will be interchangeable.
# HYPHEN_INSENSITIVE="true"

# Uncomment the following line to disable bi-weekly auto-update checks.
# DISABLE_AUTO_UPDATE="true"

# Uncomment the following line to automatically update without prompting.
# DISABLE_UPDATE_PROMPT="true"

# Uncomment the following line to change how often to auto-update (in days).
# export UPDATE_ZSH_DAYS=13

# Uncomment the following line if pasting URLs and other text is messed up.
# DISABLE_MAGIC_FUNCTIONS=true

# Uncomment the following line to disable colors in ls.
# DISABLE_LS_COLORS="true"

# Uncomment the following line to disable auto-setting terminal title.
# DISABLE_AUTO_TITLE="true"

# Uncomment the following line to enable command auto-correction.
# ENABLE_CORRECTION="true"

# Uncomment the following line to display red dots whilst waiting for completion.
# COMPLETION_WAITING_DOTS="true"

# Uncomment the following line if you want to disable marking untracked files
# under VCS as dirty. This makes repository status check for large repositories
# much, much faster.
# DISABLE_UNTRACKED_FILES_DIRTY="true"

# Uncomment the following line if you want to change the command execution time
# stamp shown in the history command output.
# You can set one of the optional three formats:
# "mm/dd/yyyy"|"dd.mm.yyyy"|"yyyy-mm-dd"
# or set a custom format using the strftime function format specifications,
# see 'man strftime' for details.
# HIST_STAMPS="mm/dd/yyyy"

# Would you like to use another custom folder than $ZSH/custom?
# ZSH_CUSTOM=/path/to/new-custom-folder

# Which plugins would you like to load?
# Standard plugins can be found in ~/.oh-my-zsh/plugins/*
# Custom plugins may be added to ~/.oh-my-zsh/custom/plugins/
# Example format: plugins=(rails git textmate ruby lighthouse)
# Add wisely, as too many plugins slow down shell startup.
plugins=(git)

source $ZSH/oh-my-zsh.sh

# User configuration

# export MANPATH="/usr/local/man:$MANPATH"

# You may need to manually set your language environment
# export LANG=en_US.UTF-8

# Preferred editor for local and remote sessions
# if [[ -n $SSH_CONNECTION ]]; then
#   export EDITOR='vim'
# else
#   export EDITOR='mvim'
# fi

# Compilation flags
# export ARCHFLAGS="-arch x86_64"

# Set personal aliases, overriding those provided by oh-my-zsh libs,
# plugins, and themes. Aliases can be placed here, though oh-my-zsh
# users are encouraged to define aliases within the ZSH_CUSTOM folder.
# For a full list of active aliases, run `alias`.
#
# Example aliases
# alias zshconfig="mate ~/.zshrc"
# alias ohmyzsh="mate ~/.oh-my-zsh"
export WORK="/Users/bafraiki/Code/pdf_project"
alias gwc='gcc -Wall -Werror -Wextra'
alias ct='cd $WORK'
alias vf='vim -O $(fzf)'
alias chrome='open -a "Google Chrome"'
alias vim='/usr/bin/vim'

ft () { egrep -n  --exclude-dir="log" --exclude-dir="packs" --exclude-dir="node_modules" --exclude-dir="tmp" --exclude-dir="assets" --exclude-dir="coverage" --exclude-dir=".git" -Hrn $1 $WORK }
fti () { egrep -n -Hrn $2 $WORK/$1 }
dt () { sed -i 0 "100s:WORK=.*$:WORK=\"$(pwd)\":" ~/.zshrc && source ~/.zshrc }

setup_docker () {

  #delete every old setting of docker that take too much space
  rm -rf ~/Library/Containers/com.docker.docker
  #rm -rf ~/Library/Containers/com.docker.helper
  rm -rf ~/.docker
  rm -rf ~/docker ~/agent
  rm -rf ~/goinfre/docker ~/goinfre/agent
  rm ~/goinfre

  #Make sure that goinfre is good
  mkdir -p /Volumes/Storage/goinfre/bafraiki
  ln -s /Volumes/Storage/goinfre/bafraiki ~/goinfre

  #recreate dir that we delete in goinfre earlier and create symlink
  mkdir -p ~/goinfre/docker ~/goinfre/agent
  ln -s ~/goinfre/agent ~/Library/Containers/com.docker.docker
  ln -s ~/goinfre/docker ~/.docker
}

#/
#function upg()
#{
#	pathPro="$HOME/Code/projectBapt"
#	pathRen="$HOME/Code/github"
#
#	rm -rf $pathRen/beforestage
#	rm -rf $pathRen/afterpis
#	rm -rf $pathRen/testzone
#
#	for dir in `ls $pathPro`
#	do
#		cp -r $pathPro/$dir $pathRen
#		find $pathRen/$dir -name '.git' -print -exec rm -rf {} \;
#	done

#	cp $HOME/.zshrc $pathRen
#	cp $HOME/.vimrc $pathRen
#	cp $HOME/.gitconfig $pathRen
#	cp $HOME/php_piscine $pathRen
#
#	cd $pathRen
#	git add .
#	git commit -m "update of project $(date +\"%Y-%m-%d_%H-%M-%S\")"
#	git push
#	ct
#}



[ -f ~/.fzf.zsh ] && source ~/.fzf.zsh
export PATH=$HOME/.brew/bin:$PATH
export PATH="/sgoinfre/goinfre/Perso/bafraiki/miniconda3/bin/:$PATH"
