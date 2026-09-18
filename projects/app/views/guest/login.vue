<tree-sitter x11 >

	<div class="flex gap-2">
		<div>{{ device.name }}</div>
		<div>{{ device.date }}</div>
		<div>{{ device.i3 }}</div>
	</div>

	<div class="id">

		<div v:onclick="login">{{ title }}</div>

	</div>

</tree-sitter>

<script>
	way="RAW line(ref(ONCE)(KEEP)) /"
</script>
