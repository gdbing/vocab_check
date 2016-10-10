import sublime
import sublime_plugin


class CheckVocabCommand(sublime_plugin.TextCommand):

	def run(self, edit):
		regions = []
		allcontent = sublime.Region(0, self.view.size())
		line_regions = self.view.split_by_newlines(allcontent)


		for lr in line_regions:
			ls = self.view.substr(lr) + "\n"
			j = -1
			for i in range(len(ls)):
				if ls[i] not in [" ",".","\t","\n"]:
					if j == -1:
						j = i
				else :
					if j != -1:
						if False: # TODO check word against dictionary here
							regions.append(sublime.Region(lr.a + j, lr.a + i))
						j = -1

		v = sublime.active_window().active_view()
		v.add_regions(
			"hello",
			regions,
			"comment",
			"",
			sublime.DRAW_SQUIGGLY_UNDERLINE|sublime.DRAW_NO_FILL|sublime.DRAW_NO_OUTLINE)
