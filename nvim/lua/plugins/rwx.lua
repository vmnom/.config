return {

	"preservim/nerdtree",

	"ellisonleao/gruvbox.nvim",

	{
		branch = "master",

		"nvim-treesitter/nvim-treesitter",

		config = function()

			vim.cmd.colorscheme("gruvbox")

			vim.g.NERDTreeMinimalUI = 1

			vim.g.NERDTreeStatusline = ""

			vim.keymap.set("n", "<C-e>", ":NERDTreeToggle<CR>", { silent = true })

			require("nvim-treesitter.configs").setup({

				highlight = { 
					enable = true 
				},

				ensure_installed = { 
					"c",
					"cpp",
				},

			})

			vim.opt.wrap   = false

			vim.opt.number = true

			vim.api.nvim_set_hl(0, "String", { fg = "#83c092", bold = true })
			vim.api.nvim_set_hl(0, "Directory", { fg = "#e67e80", bold = true })
			vim.api.nvim_set_hl(0, "@module", { fg = "#e67e80", bold = true })
			vim.api.nvim_set_hl(0, "@keyword.type", { fg = "#e67e80", bold = true })
			vim.api.nvim_set_hl(0, "@keyword.repeat", { fg = "#e60000", bold = true })
			vim.api.nvim_set_hl(0, "@keyword.return", { fg = "#e60000", bold = true })
			vim.api.nvim_set_hl(0, "@keyword.import", { fg = "#e67e80", bold = true })
			vim.api.nvim_set_hl(0, "@keyword.modifier", { fg = "#dbbc7f", bold = true })
			vim.api.nvim_set_hl(0, "@function", { fg = "#e278ee", bold = true })
			vim.api.nvim_set_hl(0, "@function", { fg = "#e278ee", bold = true })

		end,

	},
}
