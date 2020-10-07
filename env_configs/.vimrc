"========== Plugins =========="
call plug#begin('~/.vim/plugged')

Plug 'itchyny/lightline.vim'
Plug 'preservim/nerdcommenter'
Plug 'SirVer/ultisnips'
Plug 'cohama/lexima.vim'
Plug 'sonph/onehalf', {'rtp': 'vim/'}

call plug#end()
"========== Colorcheme =========="
set termguicolors background=light
let g:lightline={'colorscheme': 'ayu_light'}
colorscheme onehalflight
"========== Settings =========="
" move to displayed line, not file line
nnoremap j gj
nnoremap k gk

" Enable Highlight Search

set hlsearch
set incsearch
set ignorecase
set smartcase
nnoremap n nzz
nnoremap N Nzz
nnoremap * *zz
nnoremap # #zz
nnoremap g* g*zz
nnoremap g# g#zz

" Press <leader> Enter to remove search highlights
noremap <silent> <leader><cr> :noh<cr>

" Shift to the next round tab stop. 
set shiftround  
" Set auto indent spacing.
set shiftwidth=4

" indentation
filetype plugin indent on
set shiftwidth=4 tabstop=4 expandtab softtabstop=4 cinoptions+=L0
set autoindent smartindent cindent

" misc vim config
set laststatus=2 noshowmode number encoding=utf-8 showcmd

" switch between absolute and relative number
augroup numbertoggle
    autocmd!
    autocmd BufEnter,FocusGained,InsertLeave * set rnu
    autocmd BufLeave,FocusLost,InsertEnter * set nornu
augroup END

" don't clear clipboard on exit
set clipboard=unnamedplus
autocmd VimLeave * call system("xsel -ib", getreg('+'))

" no backups
set nobackup noswapfile

" nerd commenter
let g:NERDSpaceDelims = 1
map <C-c> <leader>cb
map <C-x> <leader>cu

" autoformat with astyle
map <leader>fm :%!astyle --mode=c --style=google -xV -H -y -j -xf<CR>
"========== CP config =========="
set shell=/usr/bin/zsh\ -i
map <F3> :%y+<CR>
map <F9> :w <bar> !contest "%:t"<CR>
map <F10> :!run_test "%:t"<CR>
map <F8> :!run_contest "%:t"<CR>

" add template to cpp file
function AddTemplate(tmpl_file)
    exe "0read " . a:tmpl_file
    7
endfunction

autocmd BufNewFile *.cpp call AddTemplate("~/template.cpp")
"========== EOF =========="
