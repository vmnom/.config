require("plugins.lazy")

require("lazy").setup({

	{
		"neovim/nvim-lspconfig",
	},

	{
		"preservim/nerdtree",
		init = function()
			vim.keymap.set("n", "<C-e>", "<cmd>NERDTreeToggle<CR>", {
				silent = true,
			})

			vim.g.NERDTreeMinimalUI = 1
		end,
	},

	{
		"nvim-treesitter/nvim-treesitter",
		branch = "main",
		build = ":TSUpdate",
		config = function()

			require("nvim-treesitter").setup()

			vim.api.nvim_create_autocmd("FileType", {
				callback = function()
					pcall(vim.treesitter.start)
				end,
			})

			require("nvim-treesitter").install({ "lua" })
		end,
	},

	{
		"folke/tokyonight.nvim",
		lazy = false,
		priority = 1000,

		opts = {
			style = "day",

			on_colors = function(colors)
				-- Refactoring.Guru-inspired design-pattern palette
				colors.blue = "#2879B9"
				colors.blue_dark = "#1F5F91"
				colors.cyan = "#3A8C9E"

				colors.green = "#4F8A10"
				colors.green_bright = "#6AAE2A"

				colors.yellow = "#D6A700"
				colors.orange = "#D97817"

				colors.red = "#C94C4C"
				colors.purple = "#7957A8"
				colors.pink = "#C85C7A"

				-- Warm documentation / article background
				colors.bg = "#FDFBF7"
				colors.bg_dark = "#F3F0E8"
				colors.bg_float = "#FFFFFF"
				colors.bg_highlight = "#F1EEE6"

				colors.fg = "#2F3437"
				colors.fg_dark = "#6B7073"
				colors.fg_gutter = "#A0A3A4"

				colors.border = "#D9D4C8"
			end,

			on_highlights = function(hl, c)
				-- ==========================================
				-- DESIGN PATTERN / CODE SYNTAX
				-- ==========================================

				hl.Keyword = {
					fg = "#7957A8",
					bold = true,
				}

				hl.Function = {
					fg = "#2879B9",
				}

				hl.Type = {
					fg = "#3A8C9E",
					bold = true,
				}

				hl.Number = {
					fg = "#D97817",
				}

				hl.String = {
					fg = "#4F8A10",
				}

				hl.Constant = {
					fg = "#D6A700",
				}

				hl.Variable = {
					fg = "#2F3437",
				}

				hl.Operator = {
					fg = "#596166",
				}

				hl.Comment = {
					fg = "#8A8D8D",
					italic = true,
				}

				-- ==========================================
				-- DESIGN PATTERN CONCEPTS
				-- ==========================================

				-- Classes / interfaces
				hl["@type"] = {
					fg = "#3A8C9E",
					bold = true,
				}

				hl["@type.definition"] = {
					fg = "#2879B9",
					bold = true,
				}

				hl["@constructor"] = {
					fg = "#2879B9",
				}

				-- Methods / operations
				hl["@function"] = {
					fg = "#2879B9",
				}

				hl["@function.call"] = {
					fg = "#2879B9",
				}

				hl["@method"] = {
					fg = "#2879B9",
				}

				hl["@method.call"] = {
					fg = "#2879B9",
				}

				-- Properties / relationships
				hl["@property"] = {
					fg = "#3A8C9E",
				}

				hl["@field"] = {
					fg = "#3A8C9E",
				}

				hl["@variable"] = {
					fg = "#2F3437",
				}

				hl["@parameter"] = {
					fg = "#6B7073",
				}

				-- Values
				hl["@string"] = {
					fg = "#4F8A10",
				}

				hl["@number"] = {
					fg = "#D97817",
				}

				hl["@constant"] = {
					fg = "#D6A700",
				}

				-- Keywords
				hl["@keyword"] = {
					fg = "#7957A8",
					bold = true,
				}

				hl["@keyword.return"] = {
					fg = "#C94C4C",
					bold = true,
				}

				hl["@keyword.conditional"] = {
					fg = "#7957A8",
				}

				hl["@keyword.repeat"] = {
					fg = "#7957A8",
				}

				-- Operators / punctuation
				hl["@operator"] = {
					fg = "#596166",
				}

				hl["@punctuation.bracket"] = {
					fg = "#777C80",
				}

				hl["@punctuation.delimiter"] = {
					fg = "#777C80",
				}

				hl["@comment"] = {
					fg = "#8A8D8D",
					italic = true,
				}

				-- ==========================================
				-- PREPROCESSOR
				-- ==========================================

				hl.PreProc = {
					fg = "#7957A8",
					bold = true,
				}

				hl.Include = {
					fg = "#2879B9",
				}

				hl.Define = {
					fg = "#7957A8",
					bold = true,
				}

				hl.Macro = {
					fg = "#D97817",
				}

				-- ==========================================
				-- HTML / MARKUP
				-- ==========================================

				hl["@tag"] = {
					fg = "#C94C4C",
					bold = true,
				}

				hl["@tag.attribute"] = {
					fg = "#2879B9",
				}

				hl["@tag.delimiter"] = {
					fg = "#8A8D8D",
				}

				-- ==========================================
				-- EDITOR
				-- ==========================================

				hl.Normal = {
					fg = "#2F3437",
					bg = "#FDFBF7",
				}

				hl.NormalFloat = {
					fg = "#2F3437",
					bg = "#FFFFFF",
				}

				hl.FloatBorder = {
					fg = "#D9D4C8",
					bg = "#FFFFFF",
				}

				hl.CursorLine = {
					bg = "#F3F0E8",
				}

				hl.LineNr = {
					fg = "#A0A3A4",
					bg = "#FDFBF7",
				}

				hl.CursorLineNr = {
					fg = "#2879B9",
					bold = true,
				}

				hl.SignColumn = {
					bg = "#FDFBF7",
				}

				-- ==========================================
				-- SELECTION
				-- ==========================================

				hl.Visual = {
					fg = "#2F3437",
					bg = "#DCEBF5",
				}

				-- ==========================================
				-- SEARCH
				-- ==========================================

				hl.Search = {
					fg = "#2F3437",
					bg = "#F4D35E",
				}

				hl.IncSearch = {
					fg = "#FFFFFF",
					bg = "#2879B9",
					bold = true,
				}

				-- ==========================================
				-- COMPLETION
				-- ==========================================

				hl.Pmenu = {
					fg = "#2F3437",
					bg = "#FFFFFF",
				}

				hl.PmenuSel = {
					fg = "#FFFFFF",
					bg = "#2879B9",
					bold = true,
				}

				hl.PmenuSbar = {
					bg = "#F1EEE6",
				}

				hl.PmenuThumb = {
					bg = "#B8B5AC",
				}

				-- ==========================================
				-- STATUS / WINDOW UI
				-- ==========================================

				hl.StatusLine = {
					fg = "#2F3437",
					bg = "#F1EEE6",
					bold = true,
				}

				hl.StatusLineNC = {
					fg = "#8A8D8D",
					bg = "#F3F0E8",
				}

				hl.WinSeparator = {
					fg = "#D9D4C8",
				}

				-- ==========================================
				-- NVIMTREE
				-- ==========================================

				hl.NvimTreeNormal = {
					fg = "#2F3437",
					bg = "#F3F0E8",
				}

				hl.NvimTreeNormalNC = {
					fg = "#2F3437",
					bg = "#F3F0E8",
				}

				hl.NvimTreeFolderName = {
					fg = "#2879B9",
				}

				hl.NvimTreeOpenedFolderName = {
					fg = "#4F8A10",
					bold = true,
				}

				hl.NvimTreeRootFolder = {
					fg = "#2879B9",
					bold = true,
				}

				hl.NvimTreeIndentMarker = {
					fg = "#D9D4C8",
				}

				-- ==========================================
				-- DIAGNOSTICS
				-- ==========================================

				hl.DiagnosticError = {
					fg = "#C94C4C",
					bold = true,
				}

				hl.DiagnosticWarn = {
					fg = "#D97817",
				}

				hl.DiagnosticInfo = {
					fg = "#2879B9",
				}

				hl.DiagnosticHint = {
					fg = "#4F8A10",
				}

				-- ==========================================
				-- GIT / DIFF
				-- ==========================================

				hl.GitSignsAdd = {
					fg = "#4F8A10",
				}

				hl.GitSignsChange = {
					fg = "#D6A700",
				}

				hl.GitSignsDelete = {
					fg = "#C94C4C",
				}

				hl.DiffAdd = {
					fg = "#4F8A10",
					bg = "#EDF5E8",
				}

				hl.DiffChange = {
					fg = "#A07800",
					bg = "#FFF7D6",
				}

				hl.DiffDelete = {
					fg = "#C94C4C",
					bg = "#FBEAEA",
				}
			end,
		},

		config = function(_, opts)
			vim.opt.termguicolors = true

			require("tokyonight").setup(opts)

			vim.cmd.colorscheme("tokyonight")
		end,
	},
})
