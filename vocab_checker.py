import sublime
import sublime_plugin


class CheckVocabCommand(sublime_plugin.TextCommand):

	def run(self, edit):
		regions = []
		vocab_list = []

		# initialize vocab list
		v = open('vocab_checker/vocab.txt', 'rU')
		for line in v:
			print(line)
			vocab_list.append(line.rstrip())

		allcontent = sublime.Region(0, self.view.size())
		line_regions = self.view.split_by_newlines(allcontent)

		for lr in line_regions:
			ls = self.view.substr(lr) + "\n"
			j = -1
			for i in range(len(ls)):
				if ls[i] not in [" ",".","\t","\n","!","?","—"]:
					if j == -1:
						j = i
				else :
					if j != -1:
						word_region = sublime.Region(lr.a + j, lr.a + i)
						if self.view.substr(word_region) in vocab_list:
							regions.append(word_region)
						j = -1

		v = sublime.active_window().active_view()
		v.add_regions(
			"hello",
			regions,
			"comment",
			"",
			sublime.DRAW_SQUIGGLY_UNDERLINE|sublime.DRAW_NO_FILL|sublime.DRAW_NO_OUTLINE)

# TODO handle word sequences

# how will you check to see if the hover was over an underlined region?
# i will initially probably just check them all with
# for r in regions: if r.contains(point): do_thing()
# but later I will probably replace that with a callback function with do_thing as a parameter
# and do some kind of O(logn) search algorithm. check centre, eliminate half. centre of remainder, elminate half, etc.
